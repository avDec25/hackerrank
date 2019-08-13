#include <bits/stdc++.h>

#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
using pii = pair<int,int>;
#define INF (numeric_limits<int>::max())
#define nINF (numeric_limits<int>::min())

pii combine(pii a, pii b) {
	if (a.first > b.first) {
		return a;
	}

	if( b.first > a.first ) {
		return b;
	}
	
	return make_pair(a.first, a.second + b.second);
}

void build(	pii* st,
			vector<int>& a,
			int v,
			int cl,
			int cr)
{
	if (cl == cr) {
		st[v].first = a[cl];
		st[v].second = 1;
		return;
	}
	int cm = (cl + cr) / 2;
	build(st, a, 2*v, cl, cm);
	build(st, a, 2*v+1, cm+1, cr);
	st[v] = combine(st[2*v], st[2*v+1]);
}

pii getmax(pii* st, int v, int cl, int cr, int ql, int qr) {
	if (ql > qr) {
		return {0, 0};
	}
	if (ql == cl && qr == cr) {
		return st[v];
	}
	int cm = (cr + cl) / 2;
	return 	combine(getmax(st, 2*v, cl, cm, ql, min(cm, qr)),
					getmax(st, 2*v+1, cm+1, cr, max(cm+1, ql), qr)
	);
}

void update(pii* st, int v, int cl, int cr, int pos, int new_val)
{
	if (cl == cr) {
		st[v] = make_pair(new_val, 1);
		return ;
	}
	int cm = (cr + cl) / 2;
	if(pos <= cm)
		update(st, 2*v, cl, cm, pos, new_val);
	else
		update(st, 2*v+1, cm+1, cr, pos, new_val);
	st[v] = combine(st[2*v], st[2*v+1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a;
    a.push_back(0);
    for (int i = 1; i <= n; ++i) {
    	int x; cin >> x;
    	a.push_back(x);
    }
    
    pii* st = new pii[4*n];
    build(st, a, 1, 1, n);
	
	for (int i = 0; i < 4*n; ++i) {
		cout << st[i] << "\t";
	}
	cout << "\nMax Element = " << getmax(st, 1, 1, n, 1, n) << "\n\n";

	update(st, 1, 1, n, 5, 5);

	for (int i = 1; i < 4*n; ++i) {
		cout << st[i] << "\t";
	}
	cout << "\nMax Element = " << getmax(st, 1, 1, n, 1, n) << "\n\n";

    return 0;
}