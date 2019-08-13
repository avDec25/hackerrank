#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())


unordered_map<int, int> f;

int fib(int n)
{
	if (f[n]) {
		return f[n];
	}

	f[n] = fib(n-1) + fib(n-2);
	return f[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = 0;
    f[1] = 1;
    f[2] = 1;

    int t;
    cin >> t;
    cout << fib(t);

    return 0;
}