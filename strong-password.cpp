#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int minimumNumber(int n, string pass) {
    // Return the minimum number of characters to make the password strong
    unsigned digits = 1;
    unsigned lowercase = 1;
    unsigned uppercase = 1;
    unsigned special = 1;

    string spclstr = "!@#$%^&*()-+";

    if (pass.length() < 6) {
    	return 6 - pass.length();
    }
    for(auto e : pass)
    {
       	if (lowercase && islower(e)) {
    		--lowercase;
    		continue;
    	} 

    	if (uppercase && isupper(e)) {
    		--uppercase;
    		continue;
    	} 

    	if(digits && isdigit(e)) {
    		--digits;
    		continue;
    	} 

    	size_t found = spclstr.find(e);
    	if (special && found != string::npos) {
    		--special;
    	}
    }

    return digits + lowercase + uppercase + special;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string pass; cin >> pass;

    cout << minimumNumber(n, pass);

    return 0;
}