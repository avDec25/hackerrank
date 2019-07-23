#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;

void bonAppetit(vector<int> bill, int k, int b) 
{
    int total = 0;
    for(auto e : bill) {
        total += e;        
    }
    int ans = b - ((total-bill[k])/2);
    if(ans == 0) {
        cout << "Bon Appetit";
    } else {
        cout << ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> bill(n);
    for (auto& p : bill) {
		cin >> p;
 	}

	int b; cin >> b;

	bonAppetit(bill, k, b);

    return 0;
}