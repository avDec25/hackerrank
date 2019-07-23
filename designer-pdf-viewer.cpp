#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int designerPdfViewer(vector<int> h, string word) {
	int len = word.length();
	int ht = -1;
	for(auto e : word)
	{
		ht = max(ht, h[e-'a']);
	}

	return len * ht;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> h;
    for (int i = 0; i < 26; ++i)
    {
    	int x; cin >> x;
    	h.push_back(x);
    }

    string str;
    cin >> str;

    cout << designerPdfViewer(h, str);
    return 0;
}