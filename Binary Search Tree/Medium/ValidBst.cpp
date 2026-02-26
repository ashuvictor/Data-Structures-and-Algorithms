/*BST valid 
https://leetcode.com/problems/validate-binary-search-tree/
*/




class Solution {

    private boolean validate(TreeNode root, long min, long max) {
        if (root == null) return true;

        if (root.val <= min || root.val >= max)
            return false;

        return validate(root.left, min, root.val) &&
               validate(root.right, root.val, max);
    }

    public boolean isValidBST(TreeNode root) {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}



class Solution {

    private boolean valid(TreeNode root, TreeNode min, TreeNode max) {
        if (root == null)
            return true;

        if (min != null && root.val <= min.val)
            return false;

        if (max != null && root.val >= max.val)
            return false;

        boolean left = valid(root.left, min, root);
        boolean right = valid(root.right, root, max);

        return left && right;
    }

    public boolean isValidBST(TreeNode root) {
        return valid(root, null, null);
    }
}