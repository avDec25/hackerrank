#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;

string catAndMouse(int a, int b, int m) 
{
	int am = abs(a-m);
	int bm = abs(b-m);

	if (am == bm)
	{
		return "Mouse C";
	}

	if (am > bm)
	{
		return "Cat B";
	}

	return "Cat A";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
    	int a, b, m;
    	cin >> a >> b >> m;

		cout << catAndMouse(a, b, m);

    	cout << "\n";
    }

    return 0;
}