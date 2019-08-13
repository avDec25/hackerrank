#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

void build(vector<vector<int>>& st, vector<int>& a, int v, int cl, int cr)
{
	if (cl == cr) {
		st[v] = vector<int> (1, a[cl]);
	} else {
		int cm = (cr + cl)/2;
		build(st, a, 2*v, cl, cm);
		build(st, a, 2*v, cm+1, cr);
		merge(	st[2*v].begin(), st[2*v].end(),
				st[2*v+1].begin(), st[2*v+1].end(),
				back_inserter(st[v]));
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
    	int x; cin >> x;
    	a[i] = x;
    }

    		
    vector<vector<int>> st;
    st.resize(4*n, vector<int>(0));
    build(st, a, 1, 1, n);
    for (int i = 0; i < 4*n; ++i) {
    	cout << st[i] << "\n";
    }

    return 0;
}