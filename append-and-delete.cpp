#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

string appendAndDelete(string s, string t, int k) {
	if (s == t) {
		return "Yes";
	}
	int i = 0;
	while(i < s.size() && i < t.size()) {
		if(s[i] == t[i]) {
			++i;
		} else {
			break;
		}
	}

	int operations = abs((int)s.length()-i) + abs((int)t.length()-i);
	if (k%2 == (s.length()+t.length())%2) {
		operations = s.length() + t.length() - 2 * i;
	} else {
		operations = s.length() + t.length() + 1;
	}
	if (k < operations) {
		return "No";
	}
	return "Yes";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int k; cin >> k;

    cout << appendAndDelete(s, t, k) << "\n";

    return 0;
}