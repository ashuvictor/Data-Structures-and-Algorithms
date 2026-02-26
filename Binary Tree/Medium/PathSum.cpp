Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
https://leetcode.com/problems/path-sum/


class Solution {

    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null)
            return false;

        // leaf node check
        if (root.left == null && root.right == null && root.val == targetSum)
            return true;

        boolean left = hasPathSum(root.left, targetSum - root.val);
        boolean right = hasPathSum(root.right, targetSum - root.val);

        return left || right;
    }
}