https://leetcode.com/problems/binary-tree-maximum-path-sum/
/*path may or may not go from the root
three cases
1 current node is int the path of maxsum
2 current node is the root of the maxsum path
3 current node is not in the path
*/
class Solution {
public:
    int maxsum(TreeNode* root,int &result){
        if(root==NULL)
            return 0;
        int left=maxsum(root->left,result);
        int right=maxsum(root->right,result);
        int max_straight=max(max(left,right)+root->val,root->val);  //case 1
        int maxcase=max(max_straight,left+right+root->val);// comparres case 1 and 2
        result=max(result,maxcase);  // 
        return max_straight;
    }
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        maxsum(root,result);
        return result;
    }
};