https://leetcode.com/problems/increasing-order-search-tree/
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,

class Solution {

    private void inorder(TreeNode root, TreeNode[] temp) {
        if (root == null) return;

        inorder(root.left, temp);

        temp[0].right = new TreeNode(root.val);
        temp[0] = temp[0].right;

        inorder(root.right, temp);
    }

    public TreeNode increasingBST(TreeNode root) {
        TreeNode dummy = new TreeNode(); // like temp in C++
        TreeNode[] temp = new TreeNode[]{dummy}; // simulate reference

        inorder(root, temp);
        return dummy.right;
    }
}



class Solution {
    TreeNode curr;

    public TreeNode increasingBST(TreeNode root) {
        TreeNode dummy = new TreeNode();
        curr = dummy;
        inorder(root);
        return dummy.right;
    }

    private void inorder(TreeNode root) {
        if (root == null) return;

        inorder(root.left);

        root.left = null;
        curr.right = root;
        curr = root;

        inorder(root.right);
    }
}



import java.util.*;

class Solution {

    private void inorder(TreeNode root, List<Integer> list) {
        if (root == null) return;

        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }

    public TreeNode increasingBST(TreeNode root) {
        if (root == null) return null;

        List<Integer> list = new ArrayList<>();
        inorder(root, list);

        TreeNode dummy = new TreeNode();
        TreeNode temp = dummy;

        for (int val : list) {
            temp.right = new TreeNode(val);
            temp = temp.right;
        }

        return dummy.right;
    }
}