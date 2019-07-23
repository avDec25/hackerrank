#include <bits/stdc++.h>
#include "prettyprint.h"
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

bool isInside(int x, int y, int N) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}

int minimalDistance(vector<int> kpos, vector<int> tpos, int N, int xd, int yd){
	
	vector<int> dx = { +yd, -xd, -xd, -yd, -yd, +xd, +xd, +yd };
	vector<int> dy = { -xd, +yd, -yd, -xd, +xd, -yd, +yd, +xd };

	vector<vector<bool>> visit;
	visit.resize(N, vector<bool>(N, false));
	visit[kpos[0]][kpos[1]] = true;

	queue<cell> q;
	cell t(kpos[0], kpos[1], 0);
	q.push(t);

	while(!q.empty()) {
		t = q.front();
		q.pop();

		if (t.x == tpos[0] && t.y == tpos[1]) {
			return t.dis;
		}

		for (int i = 0; i < 8; ++i)
		{
			int x = t.x + dx[i];
			int y = t.y + dy[i];
			if (isInside(x, y, N)) {
				visit[x][y] = true;
				q.push(cell(x, y, t.dis+1));
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
    vector<int> knight_pos = {0, 0};
    vector<int> target_pos = {N-1, N-1};

    cout << minimalDistance(knight_pos, target_pos, N, 4, 1);

    return 0;
}