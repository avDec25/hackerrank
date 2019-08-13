#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

string str1, str2;
pair<string,string> breakon1(int i, string s) {
	str1.clear();
	str2.clear();
	if(i-1 >= 0) {
		str1 = s.substr(0, i);
		str1[i-1] = (str1[i-1] == '1')?'0' : '1';
	}
	if(i+1 < s.length()) {
		str2 = s.substr(i+1);
		str2[0] = (str2[0] == '1')?'0' : '1';		
	}
	return make_pair(str1, str2);
}

bool check(string s) {
	if (s.empty()) {
		return true;
	}
	if (s.size() == 1) {
		if(s[0] == '1')
			return true;
		else
			return false;
	}
	bool ans = false;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '1') {
			pair<string,string> pss = breakon1(i, s);
			ans |= check(pss.first) && check(pss.second);
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
    	bool ans = false;
    	string s; cin >> s;
    	for (int i = 0; i < s.length(); ++i) {
    		if (s[i] == '1') {
    			pair<string,string> pss = breakon1(i, s);
    			ans |= check(pss.first) && check(pss.second);
    		}
    	}
    	if (ans) {
    		cout << "WIN";
    	} else {
    		cout << "LOSE";
    	}
    	cout << "\n";
    }

    return 0;
}