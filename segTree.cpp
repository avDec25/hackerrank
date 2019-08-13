#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

void build(	vector<int>& st,
		   	vector<int>& a,
		   	int v,
		   	int cl,
		   	int cr) 
{
	if(cl == cr) {
		st[v] = a[cl];
		return ;	//termination condition
	}
	int cm = (cl + cr)/2;
	build(st, a, 2*v, cl, cm);
	build(st, a, 2*v+1, cm+1, cr);
	st[v] = st[2*v] + st[2*v+1];
}

int sum(vector<int>& st,
		int v,
		int cl,
		int cr,
		int ql,
		int qr) 
{
	if (ql > qr) {
		return 0;
	}
	if (cl == ql && cr == qr) {
		return st[v];
	}
	int cm = (cr + cl) / 2 ;
	return sum(st, 2*v, cl, cm, ql, min(cm, qr))
			+ sum(st, 2*v+1, cm+1, cr, max(cm+1, ql), qr);
}

void update(vector<int>& st, 
			int v, 
			int cl, 
			int cr, 
			int pos, 
			int new_val) 
{
	if (cl == cr) {
		st[v] = new_val;
		return ;
	}
	int cm = (cl + cr) / 2;
	if(pos <= cm)
		update(st, 2*v, cl, cm, pos, new_val);
	else
		update(st, 2*v+1, cm+1, cr, pos, new_val);
	st[v] = st[2*v] + st[2*v+1];
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
	cout << sum(st, 1, 1, n, 1, 4) << "\n";
	update(st, 1, 1, n, 4, 100);
	cout << sum(st, 1, 1, n, 1, 4) << "\n";

    return 0;
}