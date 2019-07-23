#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int beautifulBinaryString(string b) {
	vector<int> bimg(b.length(), 0);
	for (int i = 0; i < b.length()-2; ++i) {
		if (b[i] == '0' && b[i+1] == '1' && b[i+2] == '0') {
			bimg[i] += 1;
			bimg[i+1] += 1;
			bimg[i+2] += 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < b.length()-2; ++i) {
		if (bimg[i] == 2) {
			bimg[i] = 0;
			bimg[i-1] -= 1;
			bimg[i-2] -= 1;
			bimg[i+1] -= 1;
			bimg[i+2] -= 1;
			++ans;
		}
	}

	for (int i = 0; i < b.length()-2; ++i) {
		if (bimg[i] == 1) {
			bimg[i] = 0;
			bimg[i+1] = 0;
			bimg[i+2] = 0;
			++ans;
		}
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;
	string str; cin >> str;
	cout << beautifulBinaryString(str);

    return 0;
}