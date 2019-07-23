#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

vector<int> icecreamParlor(int m, vector<int> c) {
	vector<int> ans;
	for (int i = 0; i < c.size(); ++i)
	{
		for (int j = i+1; j < c.size(); ++j)
		{
			if (c[i] + c[j] == m) {
				return {i+1, j+1};
			}
		}
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
    	int m; cin >> m;
    	int n; cin >> n;
    	vector<int> cost(n);
    	for (auto& p : cost) cin >> p;

    	cout << icecreamParlor(m, cost);
    	cout << "\n";
    }

    return 0;
}