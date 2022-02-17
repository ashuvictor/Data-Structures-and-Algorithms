/*BST valid 
https://leetcode.com/problems/validate-binary-search-tree/
*/

class Solution {
public:
    bool valid(TreeNode* root,TreeNode* mini,TreeNode* maxi){
        if(root==NULL)
            return true;
        if(mini!=NULL and root->val<=mini->val)
            return false;
        if(maxi!=NULL and root->val>=maxi->val)
            return false;
        bool left=valid(root->left,mini,root);
        bool right=valid(root->right,root,maxi);
        return left and right;
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,NULL,NULL);
    }
};