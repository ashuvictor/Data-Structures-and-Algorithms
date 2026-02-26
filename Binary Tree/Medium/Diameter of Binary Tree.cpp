
https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
The diameter of a tree (sometimes called the width) is the number of nodes 
on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 
class Solution {

    private int height(Node root) {
        if (root == null)
            return 0;

        return Math.max(height(root.left), height(root.right)) + 1;
    }

    public int diameter(Node root) {
        if (root == null)
            return 0;

        int op1 = height(root.left) + height(root.right) + 1;
        int op2 = diameter(root.left);
        int op3 = diameter(root.right);

        return Math.max(op1, Math.max(op2, op3));
    }
}

or 



 https://leetcode.com/problems/diameter-of-binary-tree/


class Solution {
public:
    int solve(TreeNode* root,int &diameter){
        if(root==NULL)
            return 0;
        int leftd=solve(root->left,diameter);
        int rightd=solve(root->right,diameter);
        diameter=max(leftd+rightd,diameter);
        return max(leftd,rightd)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int diameter=0;
        solve(root,diameter);
        return diameter;
    }
};