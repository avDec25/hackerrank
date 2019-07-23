#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())
#define NINF (numeric_limits<int>::min())

int equalizeArray(vector<int> a) {
	unordered_map<int, int> mp;

	int mxfreq = NINF;
	for(auto e : a) {
		mp[e]++;
		mxfreq = max(mp[e], mxfreq);
	}

	return a.size() - mxfreq;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    cout << equalizeArray(a);

    return 0;
}