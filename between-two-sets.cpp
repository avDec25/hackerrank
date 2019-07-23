#include <bits/stdc++.h>
// #include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;

int getTotalX(vector<int> a, vector<int> b) 
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int ans = 0;
	int index = 0;
	for (int i = a[a.size()-1]; i <= b[0]; ++i)
	{
		bool found = true;
		for(auto e : a)
		{
			if (i % e != 0)
			{
				found = false;	
				break;
			}	
		}

		for(auto e : b)
		{
			if (e % i != 0)
			{
				found = false;	
				break;
			}	
		}

		if (found)
		{
			++ans;
		}
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a, b;

    while (n--) {
    	int x; cin >> x;
    	a.push_back(x);
    }

    while (m--) {
    	int x; cin >> x;
    	b.push_back(x);
    }

    cout << getTotalX(a, b) << "\n";
    
    return 0;
}