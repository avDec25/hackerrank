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

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (auto& p : c) cin >> p;

    int i = 0;
    int e = 100;
    do {
    	i = (i + k) % n;
    	e = e - 1 - 2*c[i];
    }while(i!=0);

    cout << e << "\n";

    return 0;
}