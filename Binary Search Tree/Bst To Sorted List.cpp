



class Solution {
    Node prev = null;

    public Node flatten(Node root) {
        inorder(root);
        return head;
    }

    Node head = null;

    private void inorder(Node curr) {
        if (curr == null) return;

        inorder(curr.left);

        if (prev == null) {
            head = curr;
        } else {
            prev.left = null;
            prev.right = curr;
        }
        prev = curr;

        inorder(curr.right);
    }
}




class Solution {

    private void inorder(Node curr, Node[] prev) {
        if (curr == null) return;

        inorder(curr.left, prev);

        prev[0].left = null;
        prev[0].right = curr;
        prev[0] = curr;

        inorder(curr.right, prev);
    }

    public Node flatten(Node root) {
        if (root == null) return null;

        Node dummy = new Node(-1);
        Node[] prev = {dummy}; // simulate reference

        inorder(root, prev);

        // last node cleanup
        prev[0].left = null;
        prev[0].right = null;

        return dummy.right;
    }
}