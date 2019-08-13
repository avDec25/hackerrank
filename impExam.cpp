#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> marked;
    for (int i = 0; i < n; ++i) {
    	string str; cin >> str;
    	marked.push_back(str);
    }

    vector<int> points(m);
    for (auto& p : points) cin >> p;

    int ans = 0;
	for (int c = 0; c < m; ++c) {
		unordered_map<int,int> v;
		int score = 0;
   		for (int r = 0; r < n; ++r) {
   			v[marked[r][c] - 'A']++;
   		}
   		if (v[0] >= v[1] && v[0] >= v[2] && v[0] >= v[3] && v[0] >= v[4]) {
			score = points[0] * v[0];
		}
		else if (v[1] >= v[0] && v[1] >= v[2] && v[1] >= v[3] && v[1] >= v[4]) {
			score = points[1] * v[1];
		}
		else if (v[2] >= v[1] && v[2] >= v[0] && v[2] >= v[3] && v[2] >= v[4]) {
			score = points[2] * v[2];
		}
		else if (v[3] >= v[1] && v[3] >= v[2] && v[3] >= v[0] && v[3] >= v[4]) {
			score = points[3] * v[3];
		}
		else if (v[4] >= v[1] && v[4] >= v[2] && v[4] >= v[3] && v[4] >= v[0]) {
			score = points[4] * v[4];
		} else {
			score = points[c];
		}
		// cout << "Score for column " << c << " = " << score << "\n";
		ans += score;
   	}

   	// cout << ans;
    return 0;
}