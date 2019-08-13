#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

struct data
{
    int sum, pref, suff, ans;
    data(){}
    data(int val): 
        sum(val), 
        pref(max(0, val)),
        suff(max(0, val)),
        ans(max(0, val)) {}
};

data combine(data l, data r) {
    data res;
    res.sum  = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans  = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}

void build(vector<data>& st, vector<int> a, int v, int cl, int cr)
{
    if (cl == cr) {
        st[v] = data(a[cl]);
    } else {
        int cm = (cr + cl) / 2;
        build(st, a, 2*v, cl, cm);
        build(st, a, 2*v+1, cm+1, cr);
        st[v] = combine(st[2*v], st[2*v+1]);
    }
}

data query(vector<data>& st, int v, int cl, int cr, int ql, int qr) {
    if (ql > qr) {
        return 0;
    }
    if (ql == cl && qr == cr) {
        return st[v];
    }
    int cm = (cr + cl) / 2;
    return combine( query(st, 2*v, cl, cm, ql, min(qr, cm)),
                    query(st, 2*v+1, cm+1, cr, max(ql, cm+1), qr));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        cin >> x;
        a[i] = x;
    }

    vector<data> st(4*n, 0);
    build(st, a, 1, 1, n);

    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        cout << query(st, 1, 1, n, x, y).ans << "\n";
    }
    return 0;
}