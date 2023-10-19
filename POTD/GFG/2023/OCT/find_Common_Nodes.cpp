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

void inorder(TreeNode* root, set<int>& s)
{
    if(root==NULL)
        return;

    inorder(root->left, s);
    s.insert(root->data);
    inorder(root->right, s);
}

vector<int> getCommonNodes(TreeNode* root1, TreeNode* root2)
{
    //we will store inorder tranversal of trees cause we need our ans in sorted order
    set<int> st1;
    inorder(root1, st1);

    set<int> st2;
    inorder(root2, st2);

    vector<int> ans;
    for(auto& ele : st2)
    {
        if(st1.find(ele)!=st1.end())
            ans.push_back(ele);
    }

    return ans;
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
    int n1, n2;
    cin>>n1;
    TreeNode* root1, *root2;
    while(n1--)
    {
        int x;
        cin>>x;
        root1 = insert(root1, x);
    }

    cin>>n2;
    while(n2--)
    {
        int x;
        cin>>x;
        root2 = insert(root2, x);
    }

    vector<int> ans = getCommonNodes(root1, root2);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";

    cout<<endl;
    return 0;
}


