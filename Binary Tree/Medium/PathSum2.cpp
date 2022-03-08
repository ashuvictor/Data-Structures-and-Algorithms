Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
class Solution {
public:
    void solve(TreeNode* root,int target,int sum,vector<int>&path,vector<vector<int>>&ans){
        if(root->left==NULL and root->right==NULL and sum==target){
            ans.push_back(path);
            return;
        }
        if(root->left){
            path.push_back(root->left->val);
            solve(root->left,target,sum+root->left->val,path,ans);
            path.pop_back();
        }
        if(root->right){
            path.push_back(root->right->val);
            solve(root->right,target,sum+root->right->val,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        
        vector<int>path;
        path.push_back(root->val);
        solve(root,targetSum,root->val,path,ans);
        return ans;
        
    }
};