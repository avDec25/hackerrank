#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

ll getmxsum(ll a[], ll i, ll n, unordered_map<ll, ll>& mp) {
	if (!(i < n)) {
		return 0;
	}

	if ( mp[i] ) {
		return mp[i];
	}

	mp[i] = max(a[i] + getmxsum(a, i+2, n, mp), getmxsum(a, i+1, n, mp));
	return mp[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m; cin >> m;
    for (ll i = 1; i <= m; ++i)
    {
    	unordered_map<ll, ll> mp;
    	ll n; cin >> n;
    	ll* a = new ll[n];
    	for(ll i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	cout << "Case " << i << ": ";
    	cout << getmxsum(a, 0, n, mp);
    	cout << "\n";
    }

    return 0;
}