Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

 https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1


import java.util.*;

class Solution {

    // Step 1: Store inorder values
    private void inorderTree(Node root, List<Integer> list) {
        if (root == null) return;

        inorderTree(root.left, list);
        list.add(root.data);
        inorderTree(root.right, list);
    }

    // Step 3: Refill inorder values
    private void inorderBST(Node root, List<Integer> list, int[] idx) {
        if (root == null) return;

        inorderBST(root.left, list, idx);

        root.data = list.get(idx[0]);
        idx[0]++;

        inorderBST(root.right, list, idx);
    }

    public Node binaryTreeToBST(Node root) {
        if (root == null) return null;

        List<Integer> list = new ArrayList<>();

        // store values
        inorderTree(root, list);

        // sort values
        Collections.sort(list);

        // refill tree
        int[] idx = {0}; // simulate reference
        inorderBST(root, list, idx);

        return root;
    }
}