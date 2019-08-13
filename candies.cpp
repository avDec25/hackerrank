#include <bits/stdc++.h>
// #include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

ll candies(vector<int> ratings) {
	vector<int> candies(ratings.size(), 1);
	for (int i = 1; i < ratings.size(); ++i)
	{
		if (ratings[i] > ratings[i-1]) {
			candies[i] += candies[i-1];
		}
	}
	// cout << candies << "\n";
	for (int i = ratings.size()-2; i >= 0; --i)
	{
		if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
		{
			candies[i] = candies[i+1]+1;
		}
	}
	ll sum = 0;
	for(auto e : candies)
	{
		sum += e;
	}
	return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    cout << candies(a);
    return 0;
}