#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

// void reversal(vector<int>& a, int i, int j) {
// 	while(i < j) {
// 		swap(a[i++], a[j--]);
// 	}
// }

// vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) 
// {
// 	vector<int> ans;
	
// 	reversal(a, 0, a.size()-1);
// 	reversal(a, 0, k-1);
// 	reversal(a, k, a.size()-1);

// 	for(auto e : queries) {
// 		ans.push_back(a[e]);
// 	}

// 	return ans;
// }

// vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) 
// {
// 	vector<int> ans;

// 	vector<int> x;
// 	for (int i = a.size()-k; i < a.size(); ++i) {
// 		x.push_back(a[i]);
// 	}

// 	for (int i = a.size()-1; i >= k; --i) {
// 		a[i] = a[i-k];
// 	}

// 	for (int i = 0; i < x.size(); ++i) {
// 		a[i] = x[i];
// 	}

// 	for(auto e : queries) {
// 		ans.push_back(a[e]);
// 	}
// 	return ans;
// }

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) 
{
    vector<int> ans;
    k = k % a.size();
    for(auto e : queries) {
        if (e - k >= 0) {
            ans.push_back(a[e-k]);
        } else {
            ans.push_back(a[e-k+a.size()]);
        }
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for (auto& p : a) cin >> p;

    vector<int> queries(q);
    for (auto& p : queries) cin >> p;

    cout << circularArrayRotation(a, k, queries);
    return 0;
}