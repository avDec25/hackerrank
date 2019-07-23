#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int hackerlandRadioTransmitters(vector<int> x, int k) {
	// l = -1, means last placed transmitter, 
	// and all before houses are covered
	// r = upto where the range of transmitter goes + 1
	sort(x.begin(), x.end());
	int l = -1, r = -1, ans = 0;
	for (int i = 0; i < x.size(); ++i)	{
		if (x[i] <= r) {
			continue;
		}
		if (l == -1) {
			l = x[i];
		} else if (x[i] - l > k) {
			++ans;
			// cout << i << "\t";
			if (x[i] - x[i-1] <= k) {
				l = -1;
			} else {
				l = x[i];
			}
			r = x[i-1] + k; // jumps to the next place just out of range
		}
	}

	if (l != -1) {
		return ans + 1;
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    cout << hackerlandRadioTransmitters(a, k);

    return 0;
}