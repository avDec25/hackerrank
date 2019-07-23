#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

void bigSorting(vector<string>& unsorted) {
	sort(unsorted.begin(), 
		unsorted.end(), 
		[](const auto &a, const auto &b) -> bool {
			if (a.length() == b.length()) {
				return a < b;
			} else {
				return a.length() < b.length();
			}
	});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<string> v;
    for (int i = 0; i < n; ++i)
    {
    	string x; cin >> x;
    	v.push_back(x);
    }
    
    bigSorting(v);

    for(auto e : v)
    {
    	cout << e << "\n";
    }

    return 0;
}