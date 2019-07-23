#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int revnum(int n)
{
	string str = to_string(n);
	reverse(str.begin(), str.end());
	return stoi(str);
}

int beautifulDays(int i, int j, int k) {
	int beautiful = 0;
    while (i <= j) {
    	int revi = revnum(i);
    	if (abs(i-revi)%k == 0) {
    		++beautiful;
    	}
    	++i;
    }
    return beautiful;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int i, j, k;
    cin >> i >> j >> k;

    cout << beautifulDays(i, j, k);

    return 0;
}