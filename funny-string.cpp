#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

string funny(string rs) {
	string str = rs;
	reverse(begin(rs), end(rs));

	bool ans = true;
	for (int i = 0; i < str.length()-1; ++i) {
		if (abs(str[i]-str[i+1]) != abs(rs[i]-rs[i+1]))
		{
			ans = false;
			break;
		}
	}

	if(ans) {
		return "Funny";
	} else {
		return "Not Funny";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
    	string str;
    	cin >> str;
    	cout << funny(str);

    	cout << "\n";
    }

    return 0;
}