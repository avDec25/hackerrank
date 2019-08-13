#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())
#define nINF (numeric_limits<ll>::min())

ll largestRectangle(vector<int> h) {
	ll ans = 0;
	ll area = 0;
	stack<int> stk;
	int i = 0;
	while( i < h.size() ) {
		if (stk.empty() || h[stk.top()] <= h[i]) {
			stk.push(i);
			++i;
		} else {
			// means at current i a smaller bar is present
			int tp = stk.top();
			stk.pop();
			area = h[tp] * (stk.empty()? i : (i - stk.top() - 1));
			ans = max(area, ans);
		}
	}

	while( !stk.empty() ) {
		int tp = stk.top();
		stk.pop();
		area = h[tp] * (stk.empty()? i : (i - stk.top() - 1) );
		ans = max(area, ans);
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    cout << largestRectangle(a);

    return 0;
}