https://leetcode.com/problems/increasing-order-search-tree/
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,

class Solution {
public:
    void inorder(TreeNode* root,TreeNode* &temp)
    {
        if(root==NULL)
            return;
        inorder(root->left,temp);
       temp->right=new TreeNode(root->val);
        temp=temp->right;
        inorder(root->right,temp);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
       TreeNode* temp=new TreeNode();
        TreeNode* ans=temp;
        inorder(root,temp);
        return ans->right;
    }
};

lass Solution {
public:
    void inorder(TreeNode* root,vector<int>&v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
            return root;
     vector<int>v;
        inorder(root,v);
        TreeNode* temp=new TreeNode();
        TreeNode* ans=temp;
        for(auto x:v)
        {
            TreeNode* curr=new TreeNode(x);
           temp->right=curr;
           temp=temp->right;
        }
        return ans->right;
    }
};