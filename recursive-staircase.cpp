#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

#define modulo 10000000007
unordered_map<int, int> n_ways;

int stepPerms(int n) {
	if (n_ways[n]) {
		return n_ways[n];
	}
	int w1 = stepPerms(n-1);
	int w2 = stepPerms(n-2);
	int w3 = stepPerms(n-3);
	n_ways[n] = (w1 + w2 + w3) % modulo;
	return n_ways[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    n_ways[1] = 1;
    n_ways[2] = 2;
    n_ways[3] = 4;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
    	int x; cin >> x;
    	cout << stepPerms(x) << "\n";
    }

    return 0;
}