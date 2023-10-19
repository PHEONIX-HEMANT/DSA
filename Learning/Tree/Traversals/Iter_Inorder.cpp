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

vector<int> inorder(TreeNode* root)
{
    vector<int> in;
    stack<TreeNode*> s;
    // s.push(root);
    TreeNode* curr = root;
    while(curr || !s.empty())
    {

        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }

        TreeNode* node = s.top();
        s.pop();
        in.push_back(node->data);
        if(node->right)
            curr = node->right;

    }

    return in;
}

int main()
{
    int x;
    TreeNode* root;
    while(cin >> x)
    {
        root = insert(root, x);
    }

    vector<int> ans = inorder(root);
    for(auto& i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}