#include <bits/stdc++.h>
// #include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

struct cell
{
    int x, y, dis;
    cell() {}
    cell(int x, int y, int dis): x(x), y(y), dis(dis) {}
};

bool isInside(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int minimumMoves(vector<vector<char>> grid, 
    int sx, int sy, int gx, int gy, int n) 
{
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    queue<cell> q;
    vector<vector<bool>> visited;
    visited.resize(n, vector<bool>(n, false));

    q.push(cell(sx, sy, 0));    
    visited[sx][sy] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'X') {
                visited[i][j] = true;
            }
        }
    }
    
    while(!q.empty()) {
        cell t = q.front();
        q.pop();
        if (t.x == gx && t.y == gy) {
            return t.dis;
        }        
        for (int i = 0; i < dx.size(); ++i) 
        {
            int x = t.x + dx[i];
            int y = t.y + dy[i];
            while(isInside(x, y, n) && !visited[x][y]) 
            {
                visited[x][y] = true;
                if (x == gx && y == gy) {
                    return t.dis+1;
                }
                x += dx[i]; y += dy[i];
            }
            q.push(cell(x-dx[i], y-dy[i], t.dis+1));
        }
    }
    return -1;
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