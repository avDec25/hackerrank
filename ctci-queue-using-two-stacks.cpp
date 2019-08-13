#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> s1;
    stack<int> s2;

	int t; cin >> t;
	while(t--) {
		int op;
		cin >> op;

		switch(op) {
			case 1:
				int element; cin >> element;
				s1.push(element);
				break;

			case 2:
				if (s2.empty()) {
					while(!s1.empty()) {
						int ele = s1.top();
						s1.pop();
						s2.push(ele);
					}
				}
				s2.pop();
				break;

			case 3:
				if (s2.empty()) {
					while(!s1.empty()) {
						int ele = s1.top();
						s1.pop();
						s2.push(ele);
					}
				} 
				cout << s2.top() << "\n";
				break;

			default:
				break;
		}
	}

    return 0;
}