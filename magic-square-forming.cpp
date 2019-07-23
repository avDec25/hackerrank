#include <bits/stdc++.h>
#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

bool isMS(vector<int> v)
{
    int k = 0;
    vector<vector<int>> matrix;
    matrix.resize(3, vector<int>(3, 0));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            matrix[i][j] = v[k];
            ++k;
        }
    }
    int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        sum += matrix[0][i];
    }

    // check if all rows okay
    for (int i = 0; i < 3; ++i)
    {
        int srow = 0;
        for (int j = 0; j < 3; ++j)
        {
            srow += matrix[i][j];
        }
        if(srow != sum) {
            return false;
        }
    }

    // check all columns okay
    for (int j = 0; j < 3; ++j)
    {
        int scol = 0;
        for (int i = 0; i < 3; ++i)
        {
            scol += matrix[i][j];
        }
        if(scol != sum) {
            return false;
        }
    }

    //check all diagonals okay
    int sdia = 0;
    int srdia = 0;
    for (int i = 0; i < 3; ++i)
    {
        sdia += matrix[i][i];
        srdia += matrix[i][2-i];
    }
    if (sdia != sum || srdia != sum) {
        return false;
    }

    return true;
}

void generateAllMagicSquares(vector<vector<int>>& ms)
{
    vector<int> v(9,0);
    for (int i = 0; i < 9; ++i) {
        v[i] = i+1;
    }

    do {
        if( isMS(v) ) {
            ms.push_back(v);
        }
    } while(next_permutation(v.begin(), v.end()));
}

int md(vector<int> a, vector<int> b) {
    int diff = 0;
    for (int i = 0; i < 9; ++i)
    {
        diff += abs(a[i]-b[i]);
    }
    return diff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> s(9,0);
    for (auto& p : s) cin >> p;    

    vector<vector<int>> ms;
    generateAllMagicSquares(ms);

    int diff = INF;
    for (int i = 0; i < ms.size(); ++i)
    {
        diff = min(diff, md(ms[i], s));
    }

    cout << diff << "\n";
    return 0;
}





















