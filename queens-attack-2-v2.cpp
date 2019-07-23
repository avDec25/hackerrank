#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

bool inRange(int x, int y, int n) {
	return (x > 0 && y > 0 && x <= n && y <= n);
}

int move(	int qx, int qy, int mvx, int mvy, 
			int n, int k, map<pair<int,int>, int> obstacles)  {
	int ans = 0;
	qx += mvx;
	qy += mvy;
	while(  inRange(qx, qy, n) ) {
		if (obstacles[{qx, qy}]) {
			break;
		}
		++ans;
		qx += mvx;
		qy += mvy;
	}

	return ans;
}

int queensAttack(int n, int k, int x, int y, vector<vector<int>> obstacles) 
{
	map<pair<int,int>, int> mp;
	for(auto e : obstacles) {
		mp[{e[0],e[1]}] = 1;
	}

	int ans = 0;
	ans += move(x, y, 1, 0, n, k, mp);
	ans += move(x, y, -1, 0, n, k, mp);
	ans += move(x, y, 0, 1, n, k, mp);
	ans += move(x, y, 0, -1, n, k, mp);
	ans += move(x, y, -1, 1, n, k, mp);
	ans += move(x, y, 1, 1, n, k, mp);
	ans += move(x, y, 1, -1, n, k, mp);
	ans += move(x, y, -1, -1, n, k, mp);
	return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	int rq, cq;
	cin >> rq >> cq;

	vector<vector<int>> obstacles;
	for (int i = 0; i < k; ++i) {
		int xr, xc;			cin >> xr >> xc;
		vector<int> obs;
		obs.push_back(xr);	obs.push_back(xc);
		obstacles.push_back(obs);
	}

	cout << queensAttack(n, k, rq, cq, obstacles);

    return 0;
}