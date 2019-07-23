#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())
vector<int> permutationEquation(vector<int> p) {
	int i = 1;
	unordered_map<int, int> mp;
	for(auto e : p) {
		mp[e] = i++;
	}
	vector<int> y;
	for (int x = 1; x <= p.size(); ++x) {
		y.push_back(mp[mp[x]]);
	}
	return y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    cout << permutationEquation(a);
    return 0;
}