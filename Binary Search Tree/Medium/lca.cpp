class Solution {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null)
            return null;

        // both nodes in right subtree
        if (root.val < p.val && root.val < q.val)
            return lowestCommonAncestor(root.right, p, q);

        // both nodes in left subtree
        else if (root.val > p.val && root.val > q.val)
            return lowestCommonAncestor(root.left, p, q);

        // split point = LCA
        else
            return root;
    }
}