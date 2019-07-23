#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

string angryProfessor(int k, vector<int> a) {
	int ontime = 0;
	for(auto e : a)
	{
		if (e <= 0) {
			++ontime;
		}
	}

	if (ontime >= k) {
		return "NO";
	} else {
		return "YES";
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
    	int n, k; cin >> n >> k;
    	vector<int> a(n);
    	for (auto& p : a) cin >> p;

    	cout << angryProfessor(k, a);
    	cout << "\n";
    }

    return 0;
}