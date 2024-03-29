#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int maxSubsetSum(vector<int> a) 
{
	int inclu = 0;
	int exclu = 0;
	int pinclu = 0;
	for (int i = 0; i < a.size(); ++i) {
		pinclu = inclu;
		inclu = max(a[i] + exclu, a[i]);
		exclu = max(exclu, pinclu);
	}

	return max(inclu, exclu);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    cout << maxSubsetSum(a);

    return 0;
}