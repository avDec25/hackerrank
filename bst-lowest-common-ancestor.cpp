#include <bits/stdc++.h>
//#include "prettyprint.h"
using namespace std;
//using namespace std::chrono;
using ll = long long;
#define INF (numeric_limits<int>::max())
struct node {
    int val;
    node* left;
    node* right;
};
node* createNewNode(int x)
{
    node* nn = new node;
    nn->val = x;
    nn->left  = nullptr;
    nn->right = nullptr;

    return nn;
}
void bstInsert(node* &root, int x)
{
    if(root == nullptr) {
        root = createNewNode(x);
        return;
    }
    if(x < root->val)
    {
        if(root->left == nullptr) {
            root->left = createNewNode(x);
            return;
        } else {
            bstInsert(root->left, x);
        }
    }
    if( x > root->val )
    {
        if(root->right == nullptr) {
            root->right = createNewNode(x);
            return;
        } else {
            bstInsert(root->right, x);
        }
    }
}
vector<int> preorder(node* root)
{
    vector<int> ans;
    function<void(node*)> po = [&](node* root) {
        if(root == nullptr) {
            return;
        }

        ans.push_back(root->val);
        po(root->left);
        po(root->right);
    };
    po(root);
    return ans;
}
vector<int> inorder(node* root)
{
    vector<int> ans;
    function<void(node*)> io = [&](node* root) {
        if(root == nullptr) {
            return;
        }

        io(root->left);
        ans.push_back(root->val);
        io(root->right);
    };
    io(root);
    return ans;
}
node* bstSearch(node* root, int key) 
{ 
    if (root == nullptr || root->val == key) 
       return root; 
    
    if (root->val < key) 
       return bstSearch(root->right, key); 
  
    return bstSearch(root->left, key); 
} 
node* bstDelete(node* root, int key) 
{    
    if (root == nullptr) 
        return root;   
    if (root->val > key) { 
        root->left = bstDelete(root->left, key); 
        return root; 
    } 
    else if (root->val < key) { 
        root->right = bstDelete(root->right, key); 
        return root; 
    } 
    if (root->left == nullptr) { 
        node* temp = root->right; 
        delete root; 
        return temp; 
    } 
    else if (root->right == nullptr) { 
        node* temp = root->left; 
        delete root; 
        return temp; 
    } 
    else {   
        node* succParent = root->right; 
        node *succ = root->right; 
        while (succ->left != nullptr) { 
            succParent = succ; 
            succ = succ->left; 
        } 
        succParent->left = succ->right; 
        root->val = succ->val; 
        delete succ;          
        return root; 
    } 
} 
map<node*,node*> genparentmap(node* root)
{
    map<node*, node*> parentof;
    if (root == nullptr) {
        return parentof;
    }
    parentof[root] = nullptr;
    function<void(node*)> genp = [&](node* ptr) {
        if (ptr->left != nullptr)
        {
            parentof[ptr->left] = ptr;
            genp(ptr->left);
        }
        if (ptr->right != nullptr)
        {
            parentof[ptr->right] = ptr;
            genp(ptr->right);
        }
    };
    genp(root);
    return parentof;    
}
// driver
node* root = nullptr;
int x;
while(cin >> x) {
    bstInsert(root, x);
    cout << x << " ";
}
vector<int> ans = preorder(root);
cout << "\nPreorder:\n";
for(auto e : ans) {
    cout << e << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--)
    {
    	ll n; cin >> n;

    	

    	cout << "\n";
    }

    return 0;
}