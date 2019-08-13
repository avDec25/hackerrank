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

    int t;
    cin >> t;
    while(t--)
    {
    	ll n, k; cin >> n >> k;
    	ll x = n/k;
    	x = x % k;
    	x = x % k;
    	if (x == 0) {
    		cout << "NO";
    	} else {
    		cout << "YES";
    	}
    	cout << "\n";
    }

    return 0;
}