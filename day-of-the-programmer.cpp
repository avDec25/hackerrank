#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
using ll = long long;

string dayOfProgrammer(int year) 
{
    if (year == 1918) { // transition
        return "26.09.1918";
    } else { // gregorian and/or julian
        if ((year < 1918 && year % 4 == 0) || (year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return "12.09." + to_string(year);
        } else {
            return "13.09." + to_string(year);
        }
    }  
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cout << dayOfProgrammer(t);

    return 0;
}