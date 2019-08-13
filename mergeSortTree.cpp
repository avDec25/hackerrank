/**
 * finding the smallest number which is greater than or equal to a given number
 * within a segment.
 * No modification queries
 */
#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

void build(vector<vector<int>>& st, int a[], int v, int cl, int cr) {
	if (cl == cr) {
		st[v] = vector<int> (1, a[cl]);
	} else {
		int cm = (cr + cl) / 2;
		build(st, a, 2*v, cl, cm);
		build(st, a, 2*v+1, cm+1, cr);
		merge(st[2*v].begin(), st[2*v].end(), st[2*v+1].begin(), st[2*v+1].end(),
			back_inserter(st[v]));
	}
}

int query(vector<vector<int>>& st, int v, int cl, int cr, int ql, int qr, int x) {
	if (ql > qr) {
		return INF;
	}
	if (ql == cl && qr == cr) {
		vector<int>::iterator pos = lower_bound(st[v].begin(), st[v].end(), x);
		if (pos != st[v].end()) {
			return *pos;
		} else {
			return INF;
		}
	}

	int cm = (cr + cl) / 2;
	return min(	query(st, 2*v, cl, cm, ql, min(qr, cm), x),
				query(st, 2*v+1, cm+1, cr, max(ql, cm+1), qr, x));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r, x;
    cin >> l >> r >> x;

    int n; cin >> n;
    int* a = new int[4*n];
    for (int i = 1; i <= n; ++i) {
    	int w; cin >> w;
    	a[i] = w;
    }
    
    vector<vector<int>> st(4*n+1);
	build(st, a, 1, 1, n);
	// for(auto e : st) {
	// 	cout << e << "\n";
	// }

	cout << query(st, 1, 1, n, l, r, x);
    return 0;
}