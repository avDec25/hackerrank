#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int nonDivisibleSubset(int k, vector<int> S)
{
	unordered_map<int, int> mp;
	for(auto e : S) {
		mp[e%k]++;
	}

	int ans = min(mp[0], 1);
	if ( k % 2 == 0 ) {
		mp[k/2] = min( mp[k/2], 1 );
	}

	for (int i = 1; i <= k/2; ++i) {
		ans += max(mp[i], mp[k-i]);
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    cout << nonDivisibleSubset(k, a);

    return 0;
}