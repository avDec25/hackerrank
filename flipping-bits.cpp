#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        unsigned u;
        cin >> u;
        string ustr(32,'1');
        for (int i = 31; i >= 0; --i)
        {
            if (u%2 == 0) {
                ustr[i] = '1';
            } else {
                ustr[i] = '0';
            }
            u /= 2;
        }
        cout << stoll(ustr,nullptr,2) << "\n";
    }

    return 0;
}