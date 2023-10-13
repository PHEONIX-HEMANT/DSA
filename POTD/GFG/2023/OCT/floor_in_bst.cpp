#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left, *right;

    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

};

int getFloor(TreeNode* root, int x, int& ans)
{
    if(root==NULL)
        return ans;

    
    if(root->data > x)
        return getFloor(root->left, x, ans);

    if(root->data < x){
        int maxi = max(root->data, ans);
        return getFloor(root->right, x , maxi);
    }

    return x;
}

TreeNode* insert(TreeNode* root,int val)
{
    if(root==NULL)
    {
        TreeNode* node = new TreeNode(val);
        return node;
    }

    if(val < root->data)
        root->left = insert(root->left, val);

    if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

int main()
{
    int n;
    cin>>n;

    TreeNode* root = NULL;

    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        root = insert(root, val);
    }

    int x;
    cin >> x;
    int ans = -1;
    cout<<getFloor(root, x, ans)<<endl;
    return 0;
}