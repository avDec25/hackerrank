#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

void build(vector<int>& st, vector<int>& a, int v, int cl, int cr)
{
	if (cl == cr) {
		st[v] = a[cl];
	} else {
		int cm = (cl + cr) / 2;
		build(st, a, 2*v, cl, cm);
		build(st, a, 2*v+1, cm+1, cr);
		st[v] = (st[2*v] * st[2*v+1]) / __gcd(st[2*v], st[2*v+1]);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n+1,0);
    for (int i = 1; i <= n; ++i) {
    	int x; cin >> x;
    	a[i] = x;
    }
    
    vector<int> st(4*n, 0);
    build(st, a, 1, 1, n);
    for (int i = 0; i <= 4*n; ++i) {
    	cout << st[i] << "\t";
    }
    cout << "\n";

    return 0;
}