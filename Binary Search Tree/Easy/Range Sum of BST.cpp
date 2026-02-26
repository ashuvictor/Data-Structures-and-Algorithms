

https://leetcode.com/problems/range-sum-of-bst/

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
class Solution {

    private int solve(TreeNode root, int low, int high) {
        if (root == null)
            return 0;

        // node within range
        if (root.val >= low && root.val <= high) {
            return root.val
                    + solve(root.left, low, high)
                    + solve(root.right, low, high);
        }

        // too large → go left only
        else if (root.val > high) {
            return solve(root.left, low, high);
        }

        // too small → go right only
        else {
            return solve(root.right, low, high);
        }
    }

    public int rangeSumBST(TreeNode root, int low, int high) {
        return solve(root, low, high);
    }
}



public int rangeSumBST(TreeNode root, int low, int high) {
    Stack<TreeNode> stack = new Stack<>();
    stack.push(root);
    int sum = 0;

    while (!stack.isEmpty()) {
        TreeNode node = stack.pop();
        if (node == null) continue;

        if (node.val >= low && node.val <= high)
            sum += node.val;

        if (node.val > low) stack.push(node.left);
        if (node.val < high) stack.push(node.right);
    }
    return sum;
}


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