#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

#define ON_LEFT 0
#define ON_RIGHT 1
#define ON_TOP 2
#define ON_BOTTOM 3
#define ON_TL 4
#define ON_TR 5
#define ON_BL 6
#define ON_BR 7

int pos(int ox, int oy, int qx, int qy)
{
	if (qy == oy) {
		if (qx < ox) {
			return ON_LEFT;
		} else {
			return ON_RIGHT;
		}
	}

	if (qx == ox) {
		if (qy < oy) {
			return ON_TOP;
		} else {
			return ON_BOTTOM;
		}	
	}

	if (ox < qx && oy > qy) {
		return ON_TL;
	}

	if (ox > qx && oy > qy) {
		return ON_TR;
	}

	if (ox < qx && oy < qy) {
		return ON_BL;
	}

	if (ox > qx && oy < qy) {
		return ON_BR;
	}

	return -1;
}

int queensAttack(int n, int k, int x, int y, vector<vector<int>> obstacles) {
	int left   = abs(x-1);
	int right  = abs(n-x);
	int top    = abs(n-y);
	int bottom = abs(y-1);

	int tl = min(top, left);
	int tr = min(top, right);
	int bl = min(bottom, left);
	int br = min(bottom, right);

	int xtl = x-1 * tl;
	int ytl = y+1 * tl;
	int xtr = x+1 * tr;
	int ytr = y+1 * tr;
	int xbl = x-1 * bl;
	int ybl = y-1 * bl;
	int xbr = x+1 * br;
	int ybr = y-1 * br;

	int total_blocked = 0;
	for(auto obs : obstacles) {
		int blocked = 1;
		int ox = obs[0];
		int oy = obs[1];
		switch( pos(ox, oy, x, y) ) {
			case ON_LEFT:
				blocked += abs(ox - 1);
				break;

			case ON_RIGHT:
				blocked += abs(n - ox);
				break;

			case ON_TOP:
				blocked += abs(n - oy);
				break;

			case ON_BOTTOM:
				blocked += abs(oy - 1);
				break;

			case ON_TL:
				blocked += abs(ox - xtl);
				break;

			case ON_TR:
				blocked += abs(xtr - ox);
				break;

			case ON_BL:
				blocked += abs(ox - xbl);
				break;

			case ON_BR:
				blocked += abs(xbr - ox);
				break;

			default:
			;
		}
		total_blocked += blocked;
	} // end of for: obstacles

	return  left + right + top + bottom + tl + tr + bl + br - total_blocked + k;
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