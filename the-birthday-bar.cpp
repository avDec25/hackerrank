#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> bar;
    while(n--) {
    	int x; cin >> x;
    	bar.push_back(x);
    }

    int d, m;
    cin >> d >> m;

    int sum = 0, i = 0, ways = 0;
    for (; i < m; ++i)
    {
    	sum += bar[i];    	
    }
    if (sum == d) {
		++ways;
	}

    for (; i < bar.size(); ++i)
    {
    	// cout << sum  << "+" << bar[i] << "-" << bar[i-m] << "(" << i-m <<")    = ";
    	sum = sum + bar[i] - bar[i-m];
    	// cout << sum << "\n";
    	if (sum == d) {
    		++ways;
    	}
    }

    cout << ways << "\n";

    return 0;
}