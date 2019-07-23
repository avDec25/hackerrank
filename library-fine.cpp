#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int libraryFine(int dr, int mr, int yr, int dd, int md, int yd) 
{	
	if ( yd == yr ) {
		if (md == mr) {
			if (dd < dr) {
				return 15 * (dr - dd);
			} else {
				return 0;
			}
		} else {
			if (md < mr) {
				return 500 * (mr - md);
			} else {
				return 0;
			}
		}
	} else {
		if (yd < yr) {
			return 10000;
		}
	}

	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int d1, m1, y1;
    cin >> d1 >> m1 >> y1;

    int d2, m2, y2;
    cin >> d2 >> m2 >> y2;

    cout << libraryFine(d1, m1, y1, d2, m2, y2) << "\n";

    return 0;
}