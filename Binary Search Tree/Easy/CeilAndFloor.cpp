public int findCeil(TreeNode root, int key) {
    int ceil = -1;

    while (root != null) {

        if (root.val == key) {
            return root.val;
        }

        if (key > root.val) {
            root = root.right;
        } else {
            ceil = root.val;
            root = root.left;
        }
    }
    return ceil;
}
public int floorInBST(TreeNode root, int key) {
    int floor = -1;

    while (root != null) {

        if (root.val == key) {
            return root.val;
        }

        if (key > root.val) {
            floor = root.val;
            root = root.right;
        } else {
            root = root.left;
        }
    }
    return floor;
}