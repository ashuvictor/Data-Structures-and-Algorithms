Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
https://leetcode.com/problems/binary-tree-paths/


class Solution {
public:
    void binaryTree(TreeNode* root,vector<string>&ans,string s)
    {
        if(root->left==NULL and root->right==NULL)
        {ans.push_back(s);
        return;}
        if(root->left)
            binaryTree(root->left,ans,s+"->"+to_string(root->left->val));
        if(root->right)
            binaryTree(root->right,ans,s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
     vector<string>ans;
        if(root==NULL)
            return ans;
        binaryTree(root,ans,to_string(root->val));
        return ans;
    }
};