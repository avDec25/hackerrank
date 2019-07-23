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
	vector<string> allstr;
	while(n--)
	{
		string str;
		cin >> str;
		allstr.push_back(str);
	}

	int q; cin >> q;
	vector<string> allquery;
	while(q--) {
		string str;
		cin >> str;
		allquery.push_back(str);
	}


	for(auto q : allquery)
	{
		int ans = 0;
		for(auto e : allstr)
		{
			if(e == q) {
				++ans;
			}
		}
		cout << ans << "\n";
	}

    return 0;
}