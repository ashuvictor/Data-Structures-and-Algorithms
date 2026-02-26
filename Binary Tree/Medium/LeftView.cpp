https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
import java.util.*;

class Solution {

    public List<Integer> leftView(Node root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;

        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int size = queue.size();

            // first node of this level
            ans.add(queue.peek().data);

            while (size-- > 0) {
                Node curr = queue.poll();

                if (curr.left != null)
                    queue.offer(curr.left);
                if (curr.right != null)
                    queue.offer(curr.right);
            }
        }

        return ans;
    }
}