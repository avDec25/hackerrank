#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int picking(vector<int> a) {
	unordered_map<int, int> mp;
	for(auto e : a) {
		mp[e]++;
	}
	
	int ans = 0;
	for(auto e : mp)
	{
		int cand = e.first;
		
		int v1 = 0, v2 = 0;
		auto cd1 = mp.find(cand+1);
		if ( cd1 != mp.end() ) {
			v1 = cd1->second;
		}

		auto cd2 = mp.find(cand-1);
		if ( cd2 != mp.end() ) {
			v2 = cd2->second;
		}

		ans = max(ans, mp[cand] + max(v1, v2));
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

	// cout << a << "\n";
    cout << picking(a);

    return 0;
}