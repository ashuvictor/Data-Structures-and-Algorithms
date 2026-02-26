Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
https://leetcode.com/problems/binary-tree-paths/


import java.util.*;

class Solution {

    private void binaryTree(TreeNode root, List<String> ans, String path) {
        // leaf node
        if (root.left == null && root.right == null) {
            ans.add(path);
            return;
        }

        if (root.left != null) {
            binaryTree(root.left, ans, path + "->" + root.left.val);
        }

        if (root.right != null) {
            binaryTree(root.right, ans, path + "->" + root.right.val);
        }
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        if (root == null) return ans;

        binaryTree(root, ans, String.valueOf(root.val));
        return ans;
    }
}