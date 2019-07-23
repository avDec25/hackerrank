#include <bits/stdc++.h>
// #include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

ll gridlandMetro(ll n, ll m, ll k, vector<vector<ll>> track) {	
	ll ans = n * m;
	unordered_map<ll, vector<pair<ll,ll>>> tt;
	for(auto e : track) {
		tt[e[0]].push_back({e[1], e[2]});
	}

	ll blocked = 0;
    for(auto &e : tt) {
	    sort(	e.second.begin(), 
	         	e.second.end(), 
	            [](const auto& a, const auto &b) -> bool {
	                if(a.first == b.first) {
	                    return a.second < b.second;
	                }
	                return a.first < b.first;
	            }
	    );

	    auto trk = e.second;
	    ll low = trk[0].first;
	    ll high = trk[0].second;
	    for (ll i = 1; i < e.second.size(); ++i) 
	    {
	    	if ( high < trk[i].first ) {
	    		blocked += high - low + 1;
	    		low = trk[i].first;
	    		high = trk[i].second;
	    	}
	    	else if (trk[i].first <= high  &&  high < trk[i].second) {
    			high = trk[i].second;
    		}
	    	
	    }

	    blocked += high - low + 1;
    }
		
	return ans - blocked;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<ll>> track;
    for (ll i = 0; i < k; ++i) {
    	vector<ll> v;
    	ll r, c1, c2;
    	cin >> r >> c1 >> c2;
    	v.push_back(r);
    	v.push_back(c1);
    	v.push_back(c2);
    	track.push_back(v);
    }

    cout << gridlandMetro(n, m, k, track);
    return 0;
}