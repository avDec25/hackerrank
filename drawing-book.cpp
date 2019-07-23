#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;

int pageCount(int n, int p) 
{
	int mxi = n/2;

	int index = -1;
	if (p & 1) { // odd
		index = (p-1)/2;
	} else {
		index = p/2;
	}

	return min(index, mxi-index);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p; cin >> n >> p;
    cout << pageCount(n, p);
    return 0;
}