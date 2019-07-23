#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int viralAdvertising(int n) {
	int liked = 0;
	int recipients = 5;
	while(n--) {
		int fwd = recipients/2;
		liked += fwd;
		recipients = fwd * 3;
	}

	return liked;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    cout << viralAdvertising(n);

    return 0;
}