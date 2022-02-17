/*max path sum
https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/


class Solution {
public:
    int maxsum(TreeNode* root,int &result){
        if(root==NULL)
            return 0;
        int left=maxsum(root->left,result);
        int right=maxsum(root->right,result);
        int max_straight=max(max(left,right)+root->val,root->val);
        int maxcase=max(max_straight,left+right+root->val);
        result=max(result,maxcase);
        return max_straight;
    }
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        maxsum(root,result);
        return result;
    }