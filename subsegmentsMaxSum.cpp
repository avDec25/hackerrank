#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

struct data {
	int sum, pref, suff, ans;
};

data make_data(int val) {
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0, val);
    return res;
}

void print(data i) {	
	cout << "\ndata.sum  = " << i.sum;
	cout << "\ndata.pref = " << i.pref;
	cout << "\ndata.suff = " << i.suff;
	cout << "\ndata.ans  = " << i.ans;
	cout << "\n-----------------";
}

data combine(data l, data r) {
	data res;
	res.sum  = l.sum + r.sum;
	res.pref = max(l.pref, l.sum + r.pref);
	res.suff = max(r.suff, r.sum + l.suff);
	res.ans  = max(max(l.ans, r.ans), l.suff + r.pref);
	return res;
}

void build(vector<data>& st, vector<int> a, int v, int cl, int cr) {
	if (cl == cr) {
		st[v] = make_data(a[cl]);
	} else {
		int cm = (cr + cl)/2;
		build(st, a, 2*v, cl, cm);
		build(st, a, 2*v+1, cm+1, cr);
		st[v] = combine(st[2*v], st[2*v+1]);
	}
}

void update(vector<data>& st, int v, int cl, int cr, int pos, int new_val)
{
	if (cl == cr) {
		st[v] = make_data(new_val);
	} else {
		int cm = (cl+cr)/2;
		if (pos <= cm)
			update(st, 2*v, cl, cm, pos, new_val);
		else
			update(st, 2*v+1, cm+1, cr, pos, new_val);
		st[v] = combine(st[2*v], st[2*v+1]);
	}
}

data query(vector<data>& st, int v, int cl, int cr, int ql, int qr) {
	if (ql > qr) {
		return make_data(0);
	}
	if (ql == cl && qr == cr) {
		return st[v];
	}
	int cm = (cr + cl) / 2;
	return combine(	query(st, 2*v, cl, cm, ql, min(qr, cm)), 
					query(st, 2*v+1, cm+1, cr, max(ql, cm+1), qr));
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

    vector<data> st(4*n);
    build(st, a, 1, 1, n);
    for (int i = 1; i <= n; ++i) {
    	cout << "\nst[" << i << "]:";
    	print(st[i]);
    }
    cout << "\n";
    cout << query(st, 1, 1, n, 1, 20).ans << "\n";
    return 0;
}