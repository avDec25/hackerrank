#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) 
{
	vector<int> ans;

	map<int,int,greater<int>> lb;
	for(auto e : scores) {
		++lb[e];
	}

	unordered_map<int, int> lbrank;
	int k = 1;
	for(auto e : lb) {
		lbrank[e.first] = k;
		k++;
	}
	vector<int> lborder;
	for(auto e : lb) {
		lborder.push_back(e.first);
	}

	for(auto e : alice)
	{
		lborder.push_back(e);
		sort(lborder.begin(), lborder.end(), greater<int>());
		auto it = find(lborder.begin(), lborder.end(), e);
		ans.push_back(it - lborder.begin() + 1);
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int n; cin >> n;
	vector<int> scores(n);
	for (auto& p : scores) cin >> p;

	int m; cin >> m;
	vector<int> alice(m);
	for (auto& p : alice) cin >> p;

	cout << climbingLeaderboard(scores, alice) << "\n";

    return 0;
}