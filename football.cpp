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

    ll t;
    cin >> t;
    while(t--)
    {
    	int n; cin >> n;
	   	vector<int> a(n);
	   	for (auto& p : a) cin >> p;

	   	vector<int> b(n);
	   	for (auto& p : b) cin >> p;
	   	
	   	vector<int> mx(n,0);
	   	for (int i = 0; i < n; ++i) {
	   		mx[i] = max(mx[i], 20*a[i] - 10*b[i]);
	   	}

	   	cout << *max_element(mx.begin(), mx.end());

    	cout << "\n";
    }

    return 0;
}