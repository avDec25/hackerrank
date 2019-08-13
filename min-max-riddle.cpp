#include <bits/stdc++.h>
// #include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

void maxofmins(vector<int>& a) {
	for (int w = 1; w <= a.size(); ++w)
	{
		std::vector<int> mins;
		for(int i = 0; i < a.size(); ++i) {
			mins.push_back(*min_element(a.begin()+i, a.begin()+i+w));
		}
		cout << *(max_element(mins.begin(), mins.end())) << " ";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    maxofmins(a);
    return 0;
}