#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())

class segtree
{
	//int tree[200000];
	vector<int> tree(200000, 0);
	int n;
public:
	segtree(vector<int> a){
		n = a.size();
	    for (int i=0; i<n; i++)     
	        tree[n+i] = a[i]; 
	   
	    for (int i = n - 1; i > 0; --i)      
	        tree[i] = tree[i<<1] + tree[i<<1 | 1];
	};
	// ~segtree();
	void updateTreeNode(int p, int value)  
	{  
	    tree[p+n] = value; 
	    p = p+n;   
	    for (int i=p; i > 1; i >>= 1) 
	        tree[i>>1] = tree[i] + tree[i^1]; 
	} 
	int query(int l, int r)  
	{  
	    int res = 0; 
	    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
	    { 
	        if (l&1)  
	            res += tree[l++]; 
	      
	        if (r&1)  
	            res += tree[--r]; 
	    } 
	    return res; 
	} 
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //drivers
		   // 0, 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11
	vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	segtree st(a); 
	cout << st.query(0, 3) << "\n"; 
	st.updateTreeNode(2, 1); 
	cout << st.query(0, 3) << "\n";

    return 0;
}