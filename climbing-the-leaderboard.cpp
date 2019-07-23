#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) 
{
	vector<int> ans;

	stack<int> stk;
	for(auto e : scores)
	{
		if(stk.empty() || stk.top() != e)
			stk.push(e);
	}

	for(auto e : alice)
	{
		while(!stk.empty() && e >= stk.top()) {
			stk.pop();
		}
		ans.push_back(stk.size()+1);
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