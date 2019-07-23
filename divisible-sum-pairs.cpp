#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a;
    while(n--)
    {
    	int x; cin >> x;
    	a.push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
    {
    	for (int j = i+1; j < a.size(); ++j)
    	{
    		if ((a[i] + a[j]) % k == 0)
    		{
    			++ans;
    		}
    	}
    }

    cout << ans;

    return 0;
}