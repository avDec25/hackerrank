#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())
#define NINF (numeric_limits<int>::min())

string isValid(string s) {
	unordered_map<char, int> freq;
	for(auto e : s) {
		freq[e]++;
	}

	unordered_map<int, int> fof;
	for(auto e : freq) {
		fof[e.second]++;
	}
	// cout << fof << "\n";

	string ans = "YES";
	if (fof.size() > 2) {
		ans = "NO";
	} else if (fof.size() == 1) {
		ans = "YES";
	} else {
		int freq1 = 0;
		int freq2 = 0;
		int f1cc = 0;
		int f2cc = 0;
		bool toggle = true;
		for(auto e : fof)
		{
			if (toggle) {
				freq1 = e.first;
				f1cc = e.second;
				toggle = !toggle;
			} else {
				freq2 = e.first;
				f2cc = e.second;			
			}
		}
		if ((freq1 == 1 && f1cc == 1) || (freq2 == 1 && f2cc == 1)) {
			ans = "YES";
		} else if ( (abs(freq1 - freq2) == 1) && (f1cc == 1 && f2cc == 1)) {
			ans = "YES";
		} else {
			ans  = "NO";
		}
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string t;
    cin >> t;
    cout << isValid(t);
    return 0;
}