#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (auto& p : a) cin >> p;

    unordered_map<int, int> mp;
    for(auto e : a) {
    	mp[e]++;
    }

    vector<pair<int,int>> birds;// id, count
    for(auto e : mp)
    {
    	birds.push_back(make_pair(e.first,e.second));
    }

    sort(birds.begin(), birds.end(), [](const pair<int,int> &x, const pair<int,int> &y)->bool{
    	if (x.second == y.second)
    		return (x.first < y.first);
    	else
    		return (x.second > y.second);
    });

    cout << birds;
    return 0;
}