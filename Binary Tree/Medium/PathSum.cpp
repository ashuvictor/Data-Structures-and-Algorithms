Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
https://leetcode.com/problems/path-sum/


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return false;
        if(root->left==NULL and root->right==NULL and root->val==targetSum)
            return true;
        bool leftS=hasPathSum(root->left,targetSum-root->val);
        bool rightS=hasPathSum(root->right,targetSum-root->val);
        return leftS || rightS;
        
    }
};