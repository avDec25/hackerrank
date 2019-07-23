#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int b; cin >> b;
    int n; cin >> n;
    int m; cin >> m;

    vector<int> key(n);
    for (auto& p : key) cin >> p;
    
    vector<int> usb(m);
    for (auto& p : usb) cin >> p;

    // sort(key.begin(), key.end());
    // sort(usb.begin(), usb.end());

    int ans = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (key[i] + usb[j] == b) {
				cout << b;
				return 0;
			} else {
				if (key[i] + usb[j] < b)
				{
					ans = max(ans, key[i] + usb[j]);
				}
			}
		}
	}

	cout << ans;
    return 0;
}