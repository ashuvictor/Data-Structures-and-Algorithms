https://techiedelight.com/practice/?problem=LevelOrderTraversal

import java.util.*;

class Solution {

    public List<Integer> findLevelOrderTraversal(Node root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;

        Queue<Node> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int size = queue.size();

            while (size-- > 0) {
                Node temp = queue.poll();
                ans.add(temp.data);

                if (temp.left != null)
                    queue.offer(temp.left);
                if (temp.right != null)
                    queue.offer(temp.right);
            }
        }

        return ans;
    }
}