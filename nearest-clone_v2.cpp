#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<ll>::max())
unordered_map<ll, vector<ll>> adjlist;

struct node
{
	ll index;
	ll color;
	ll distance;
	node(){}
	node(ll index, ll color, ll distance): 
		index(index), color(color), distance(distance) {}
};

ll bfs(vector<ll>& cid, ll color, ll i)
{
	ll n = cid.size();
	queue<node> q;
	q.push(node(i, cid[i], 0));
	vector<bool> visited(n, 0);
	visited[i] = true;
	while(!q.empty()) {
		node temp = q.front();
		q.pop();
		if (temp.index != i && temp.color == color) {
			return temp.distance;
		}
		for(auto e : adjlist[temp.index])
		{
			if (!visited[e]) {
				visited[e] = true;
				q.push(node(e, cid[e], temp.distance+1));
			}
		}
	}
	return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    for (ll i = 0; i < m; ++i)
    {
    	ll u, v; cin >> u >> v;
    	adjlist[u-1].push_back(v-1);
    	adjlist[v-1].push_back(u-1);
    }

    vector<ll> cid(n);
    for (auto& p : cid) cin >> p;
    
    ll color; cin >> color;

	bool found = false;
	ll sol;
	ll ans = INF;
    for (ll i = 0; i < n; ++i) 
    {
		if (color == cid[i]) {
			sol = bfs(cid, color, i);
			if (sol > 0) {
				found = true;
				ans = min(sol, ans);
			}
		}
    }
    if (found) {
    	cout << ans;
    } else {
    	cout << -1;
    }
    return 0;
}