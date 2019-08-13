/**
 * finding the smallest number which is greater than or equal to a given number
 * within a segment.
 * with modification queries
 */
#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

void build(vector<multiset<int>>& st, int a[], int v, int cl, int cr) {
	if (cl == cr) {
		multiset<int> mset; mset.insert(a[cl]);
		st[v] = mset;
	} else {
		int cm = (cr + cl) / 2;
		build(st, a, 2*v, cl, cm);
		build(st, a, 2*v+1, cm+1, cr);
		set_union(st[2*v].begin(), st[2*v].end(), st[2*v+1].begin(), st[2*v+1].end(),
			inserter(st[v], begin(st[v])));
	}
}

int query(vector<multiset<int>>& st, int v, int cl, int cr, int ql, int qr, int x) {
	if (ql > qr) {
		return INF;
	}
	if (ql == cl && qr == cr) {
		multiset<int>::iterator pos = lower_bound(st[v].begin(), st[v].end(), x);
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

void update(vector<multiset<int>>& st, int a[], int v, int cl, int cr, int pos, int new_val) {
	st[v].erase(st[v].find(a[pos]));
	st[v].insert(new_val);
	if (cl != cr) {
		int cm = (cl + cr) / 2;
		if (pos <= cm) {
			update(st, a, 2*v, cl, cm, pos, new_val);
		} else {
			update(st, a, 2*v+1, cm+1, cr, pos, new_val);
		}
	} else {
		a[pos] = new_val;
	}
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
    
    vector<multiset<int>> st(4*n+1);
	build(st, a, 1, 1, n);
	for(auto e : st) {
		cout << e << "\n";
	}

	update(st, a, 1, 1, n, 2, 11);
	update(st, a, 1, 1, n, 1, 5);
	cout << query(st, 1, 1, n, l, r, x);
    return 0;
}