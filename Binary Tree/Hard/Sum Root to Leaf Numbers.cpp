https://leetcode.com/problems/sum-root-to-leaf-numbers/
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

#define ll long long
class Solution {
    ll ans =0;
    void dfs(TreeNode *root,ll val)
    {
        if(!root)
            return;
        val *=10;
        val += root->val;
        if(!root->left && !root->right)
        {
            ans+=val;
            return;
        }
        dfs(root->left,val);
        dfs(root->right,val);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root,0);
        return ans;
    }
};


class Solution {
public:
    int sumRootLeaf(TreeNode* root,int sum){
        if(!root)
            return 0;
        sum=(sum*10)+root->val;
        if(!root->left and !root->right)
            return sum;
        return sumRootLeaf(root->left,sum)+sumRootLeaf(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        return sumRootLeaf(root,0);
    }
};