#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int findmx(vector<int>& v) {
	int mx = -1;
	for(auto e : v) {
		mx = max(mx, e);
	}
	return mx;
}

int hurdleRace(int k, vector<int> height) {
	int mx = findmx(height);
	if (mx <= k) {
		return 0;
	} else {
		return mx - k;
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    cout << hurdleRace(k, a);

    return 0;
}