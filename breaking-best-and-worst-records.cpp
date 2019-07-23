#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF 0x3f3f3f3f

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    vector<int> scores;

    cin >> t;
    while(t--)
    {
    	int s; cin >> s;
    	scores.push_back(s);
    }

    int highest = scores[0];
    int hbreak = 0;

    int lowest  = scores[0];
    int lbreak = 0;

    for( auto e : scores )
    {
    	if (e > highest)
    	{
    		highest = e;
    		++hbreak;
    	}

    	if (e < lowest)
    	{
    		lowest = e;
    		++lbreak;
    	}
    }

    cout << hbreak << " " << lbreak;

    return 0;
}