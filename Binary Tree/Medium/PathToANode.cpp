https://www.interviewbit.com/problems/path-to-given-node/
import java.util.*;

class Solution {

    private boolean getPath(TreeNode root, List<Integer> path, int target) {
        if (root == null)
            return false;

        // add current node
        path.add(root.val);

        // if target found
        if (root.val == target)
            return true;

        // search left or right
        if (getPath(root.left, path, target) ||
            getPath(root.right, path, target))
            return true;

        // backtrack
        path.remove(path.size() - 1);
        return false;
    }

    public List<Integer> solve(TreeNode root, int target) {
        List<Integer> path = new ArrayList<>();
        if (root == null) return path;

        getPath(root, path, target);
        return path;
    }
}