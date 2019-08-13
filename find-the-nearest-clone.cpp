#include <bits/stdc++.h>

using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<ll>::max())
unordered_map<ll, vector<ll>> adjlist;

ll findBybfs(ll n, ll node, ll color, vector<ll>& cid)
{
	queue<ll> q;
	vector<bool> visited(n, false);
	vector<ll> distance(n, 0);
	visited[node] = true;
	q.push(node);

	while( !q.empty() )
	{
		ll t = q.front();
		q.pop();
		if (cid[t] == color && t != node ) {
			return distance[t];
		}
		for(auto e : adjlist[t]) {
			if(!visited[e]) {
				visited[e] = true;
				distance[e] = distance[t] + 1;
				q.push(e);				
			}
		}
	}
	return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   	
   	vector<ll> gf, gt;
   	ll n, m; cin >> n >> m;
   	for (ll i = 0; i < m; ++i) {
   		ll u, v; cin >> u >> v;
   		adjlist[u-1].push_back(v-1);
   		adjlist[v-1].push_back(u-1);
   	}
   	vector<ll> cid(n);
   	for (auto& p : cid) cin >> p;   	

   	ll val; cin >> val;
   	ll ans = INF;
	for (ll i = 0; i < n; ++i)
	{
		if (cid[i] == val) {
			ans = min(ans, findBybfs(n, i, val, cid));
		}
	}

	cout << ans;

    return 0;
}