#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

struct cell 
{ 
	int x, y; 
	int dis; 
	cell() {} 
	cell(int x, int y, int dis) : x(x), y(y), dis(dis) {} 
}; 

bool isInside(int x, int y, int N) 
{ 
	if (x >= 1 && x <= N && y >= 1 && y <= N) 
		return true; 
	return false; 
} 

int minStepToReachTarget(	vector<int> knightPos, 
							vector<int> targetPos, 
							int N, int xd, int yd)
{
	vector<int> dx = {-xd, -yd, yd, xd, -xd, -yd, yd, xd}; 
	vector<int> dy = {-yd, -xd, -xd, -yd, yd, xd, xd, yd}; 

	queue<cell> q; 

	q.push(cell(knightPos[0], knightPos[1], 0)); 

	cell t; 
	int x, y; 
	vector<vector<bool>> visit;
	visit.resize(N+1, vector<bool>(N+1, false));

	visit[knightPos[0]][knightPos[1]] = true; 

	while (!q.empty()) 
	{ 
		t = q.front(); 
		q.pop(); 

		if (t.x == targetPos[0] && t.y == targetPos[1]) 
			return t.dis; 

		for (int i = 0; i < 8; i++) 
		{ 
			x = t.x + dx[i]; 
			y = t.y + dy[i]; 	
			if (isInside(x, y, N) && !visit[x][y]) { 
				visit[x][y] = true; 
				q.push(cell(x, y, t.dis + 1)); 
			} 
		} 
	} 
	return -1;
} 
int main() 
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
	int N; cin >> N;
	vector<int> knightPos;
	knightPos.push_back(1);
	knightPos.push_back(1);

	vector<vector<int>> ans;
	ans.resize(N, vector<int>(N, -1));

	vector<int> targetPos;
	targetPos.push_back(N);
	targetPos.push_back(N);
	for (int i = 1; i <= N-1; ++i)
	{
		for (int j = i; j <= N-1; ++j)
		{
			ans[i][j] = minStepToReachTarget(knightPos, targetPos, N, i, j);
			ans[j][i] = ans[i][j];
		}
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0; 
} 
