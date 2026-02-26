
Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.


class Solution {

    // Count total nodes
    private void countNodes(Node root, int[] count) {
        if (root == null) return;

        countNodes(root.left, count);
        count[0]++;
        countNodes(root.right, count);
    }

    // Find kth node using inorder
    private void func(Node root, Node[] cur, Node[] prev,
                      int[] c, int k, boolean[] found) {
        if (root == null) return;

        func(root.left, cur, prev, c, k, found);

        if (prev[0] == null) {
            prev[0] = root;
            c[0]++;
        }
        else if (c[0] == k) {
            cur[0] = root;
            found[0] = true;
            c[0]++;
            return;
        }
        else if (!found[0]) {
            prev[0] = root;
            c[0]++;
        }

        func(root.right, cur, prev, c, k, found);
    }

    public float findMedian(Node root) {
        int[] n = {0};
        countNodes(root, n);

        Node[] cur = {null};
        Node[] prev = {null};
        int[] c = {1};
        int k = (n[0] / 2) + 1;
        boolean[] found = {false};

        func(root, cur, prev, c, k, found);

        // Odd nodes
        if ((n[0] & 1) == 1) {
            return cur[0].data;
        }
        // Even nodes
        else {
            return (cur[0].data + prev[0].data) / 2.0f;
        }
    }
}