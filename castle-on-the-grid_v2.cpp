#include <bits/stdc++.h>
// #include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

struct cell
{
    int x, y;
    cell() {}
    cell(int x, int y): x(x), y(y) {}
};

bool isInside(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int minimumMoves(vector<vector<char>>& grid, 
    int sx, int sy, int gx, int gy, int n) 
{
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    queue<cell> q;
    vector<vector<bool>> visited;
    visited.resize(n, vector<bool>(n, false));

    q.push(cell(sx, sy));
    visited[sx][sy] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'X') {
                visited[i][j] = true;
            }
        }
    }
    
    queue<int> distance;
    distance.push(0);
    while( !q.empty() ) 
    {
        cell t = q.front();        
        if (t.x == gx && t.y == gy) {
            return distance.front();
        }
        for (int i = 0; i < dx.size(); ++i) 
        {
            int x = t.x + dx[i];
            int y = t.y + dy[i];
            while(isInside(x, y, n) && !visited[x][y]) 
            {
                q.push(cell(x, y));
                distance.push(distance.front()+1);
                visited[x][y] = true;
                x += dx[i]; y += dy[i];
            }
        }
        q.pop();
        distance.pop();
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<char>> matrix;
    matrix.resize(n, vector<char>(n));
    for(auto& row : matrix) {
    	for(auto& e : row) {
    		cin >> e;
       	}
    }
    
    int startX, startY;
    cin >> startX >> startY;
    
    int endX, endY;
    cin >> endX >> endY;

    cout << minimumMoves(matrix, startX, startY, endX, endY, n);
    
    return 0;
}