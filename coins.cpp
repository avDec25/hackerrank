#include <bits/stdc++.h>
using namespace std;
//using namespace std::chrono;
using ll = long long;


ll cex(ll* dp, ll n) {
	if(n < 12) {
		return n;
	}
	if( dp[n] != 0 ) {
		return dp[n];
	}
	dp[n] = max(n, cex(dp,n/2) + cex(dp,n/3) + cex(dp,n/4));
	return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    while(cin >> n) {
    	ll* dp = new ll[n+1];
    	cout << cex(dp,n) << "\n";
    }

    return 0;
}