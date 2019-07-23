#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int saveThePrisoner(int p, int c, int s) {
	return (s-1+c-1)%p + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
    	int n, m, s; cin >> n >> m >> s;
    	cout << saveThePrisoner(n, m, s);
    	cout << "\n";
    }

    return 0;
}