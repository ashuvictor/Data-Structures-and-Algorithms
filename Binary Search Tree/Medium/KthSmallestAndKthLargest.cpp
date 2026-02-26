Kth smallest and largest
class Solution {

    int ans = -1;

    private void solve(TreeNode root, int k, int[] idx) {
        if (root == null) return;

        solve(root.left, k, idx);

        if (idx[0] == k) {
            ans = root.val;
            idx[0]++;
            return;
        } else {
            idx[0]++;
        }

        solve(root.right, k, idx);
    }

    public int kthSmallest(TreeNode root, int k) {
        int[] idx = {1}; // simulate pass-by-reference
        solve(root, k, idx);
        return ans;
    }
}


class Solution {

    int ans;

    public int kthSmallest(TreeNode root, int K) {
        int[] idx = {1};
        ans = -1;
        solveSmallest(root, K, idx);
        return ans;
    }

    private void solveSmallest(TreeNode root, int k, int[] idx) {
        if (root == null) return;

        solveSmallest(root.left, k, idx);

        if (idx[0] == k) {
            ans = root.val;
            idx[0]++;
            return;
        } else {
            idx[0]++;
        }

        solveSmallest(root.right, k, idx);
    }
}



class Solution {

    int ans;

    public int kthLargest(TreeNode root, int K) {
        int[] idx = {1};
        ans = -1;
        solveLargest(root, K, idx);
        return ans;
    }

    private void solveLargest(TreeNode root, int k, int[] idx) {
        if (root == null) return;

        // reverse inorder
        solveLargest(root.right, k, idx);

        if (idx[0] == k) {
            ans = root.val;
            idx[0]++;
            return;
        } else {
            idx[0]++;
        }

        solveLargest(root.left, k, idx);
    }
}



public int kthSmallest(TreeNode root, int k) {
    Stack<TreeNode> stack = new Stack<>();

    while (true) {
        while (root != null) {
            stack.push(root);
            root = root.left;
        }

        root = stack.pop();
        if (--k == 0) return root.val;

        root = root.right;
    }
}
