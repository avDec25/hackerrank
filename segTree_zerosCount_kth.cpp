#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF (numeric_limits<int>::max())

void build(vector<int>& st, vector<int>& a, int v, int cl, int cr)
{
	if (cl == cr) {
		st[v] = (a[cl] == 0)? 1 : 0;
	} else {
		int cm = (cl + cr)/2;
		build(st, a, 2*v, cl, cm);
		build(st, a, 2*v+1, cm+1, cr);
		st[v] = st[2*v] + st[2*v+1];
	}
}

int find_kth(vector<int>& st, int v, int cl, int cr, int k) {
	if (k > st[v]) {
		return -1;
	}
	if (cl == cr)
		return cl;
	int cm = (cr + cl) / 2;
	if ( st[2*v] >= k )
		return find_kth(st, v*2, cl, cm, k);
	else
		return find_kth(st, v*2+1, cm+1, cr, k - st[v*2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
    	int x; cin >> x;
    	a[i] = x;
    }
    vector<int> st(4*n, 0);
    build(st, a, 1, 1, n);
    for (int i = 0; i < 4*n; ++i) {
    	cout << st[i] << "  ";
    }
    cout << "\n";
    cout << find_kth(st, 1, 1, n, 5);
    return 0;
}