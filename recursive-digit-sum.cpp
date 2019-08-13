#include <bits/stdc++.h>
//#include "prettyprll.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;

ll sd(ll n) {
	if (n < 10) {
		return n;
	}
	ll sum = 0;
	while(n!=0) {
		sum += n%10;
		n /= 10;
	}
	return sd(sum);
}

ll superDigit(string s, ll k) {
	ll sum = 0;
	for(auto e : s) {
		sum += e-'0';
	}
	return sd(sum*k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n; ll k;
    cin >> n >> k;

    cout << superDigit(n, k);
    return 0;
}