#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;
    ll* a = new ll[n];
    for (int i = 1; i < n; ++i) {
    	cin >> a[i];
    }
    bool ans = false;
    int i = 1;
    while(i < n) {
    	if (i == t) {
    		ans = true;
    		break;
    	}
    	i += a[i];
    }
    if (ans || i==n && t==n) {
    	cout << "YES";
    } else {
    	cout << "NO";
    }

    return 0;
}