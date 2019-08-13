#include <bits/stdc++.h>
using namespace std;
//using namespace std::chrono;
using ll = long long;

ll dfs(ll node, unordered_map<ll,vector<ll>>& adjlist, vector<bool>& visited) {
	ll dfs_len = 0;
	stack<ll> s; 
	s.push(node); visited[node] = true;
	while(!s.empty()) {
		node = s.top();
		s.pop();
		for(auto e : adjlist[node])
		{
			if ( !visited[e] ) {
				visited[e] = true;
				++dfs_len;
				s.push(e);
			}
		}
	}
	return dfs_len;
}

ll solution(ll n, ll m, ll cl, ll cr, unordered_map<ll,vector<ll>>& adjlist)
{
	ll cost = 0;
	if (cl <= cr) {
		return n * cl;
	}
	vector<bool> visited(n, false);
	for (ll i = 0; i < n; ++i) {
		if ( !visited[i] ) {
			cost += dfs(i, adjlist, visited) * cr + cl;
		}
	}
	return cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q; cin >> q;
    while(q--) {
    	ll n_cities, n_roads, c_lib, c_road;
	    cin >> n_cities >> n_roads >> c_lib >> c_road;

		unordered_map<ll, vector<ll>> adjlist;
	    for (ll i = 0; i < n_roads; ++i) {
	    	ll u, v; cin >> u >> v;
	    	adjlist[u-1].push_back(v-1);
	    	adjlist[v-1].push_back(u-1);
	    }
	    cout << solution(n_cities, n_roads, c_lib, c_road, adjlist) << "\n";
    }
    return 0;
}