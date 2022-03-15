

https://leetcode.com/problems/range-sum-of-bst/

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
class Solution {
public:
    int solve(TreeNode* root,int low,int high)
    {  if(root==NULL)
        return 0;
     if(root->val>=low and root->val<=high)
         return root->val+solve(root->left,low,high)+solve(root->right,low,high);
     else if(root->val>high)
         return solve(root->left,low,high);
     else
         return solve(root->right,low,high);
        
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        if(root==NULL)
            return sum;
        sum=solve(root,low,high);
        return sum;
    }
};


 vector <int> v;
    void trav (TreeNode* root){
        
        if (!root) return;
        
        trav (root->left);
        v.push_back (root->val);
        trav (root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        
       trav(root);
        int ans=0; 
        for (int i=0; i< v.size(); i++){
             
             if (v[i] >= low and v[i] <= high){
                 
                 ans+= v[i];
             }
         }
        
         return ans;
    } 

    void inorder(TreeNode* root,int low,int high,int &sum){
        if(root==NULL){
            return;
        }
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        inorder(root->left,low,high,sum);
        inorder(root->right,low,high,sum);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        //Time complexity - o(n) , space complexity - o(1)
        inorder(root,low,high,sum);
        return sum;
    }