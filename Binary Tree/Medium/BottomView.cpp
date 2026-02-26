import java.util.*;

class Solution {

    public List<Integer> topView(Node root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;

        Queue<Pair<Node, Integer>> queue = new LinkedList<>();
        Map<Integer, Integer> map = new TreeMap<>(); // sorted by HD

        queue.offer(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<Node, Integer> pair = queue.poll();
            Node node = pair.getKey();
            int hd = pair.getValue();

            // store first occurrence only
            map.putIfAbsent(hd, node.data);

            if (node.left != null)
                queue.offer(new Pair<>(node.left, hd - 1));
            if (node.right != null)
                queue.offer(new Pair<>(node.right, hd + 1));
        }

        for (int val : map.values())
            ans.add(val);

        return ans;
    }
}

class Pair<K, V> {
    K key;
    V value;

    Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    K getKey() { return key; }
    V getValue() { return value; }
}

public List<Integer> topView(Node root) {
    Map<Integer, Integer> map = new HashMap<>();
    Queue<Pair<Node, Integer>> q = new LinkedList<>();
    q.offer(new Pair<>(root, 0));

    int min = 0, max = 0;

    while (!q.isEmpty()) {
        Pair<Node, Integer> p = q.poll();
        Node node = p.getKey();
        int hd = p.getValue();

        map.putIfAbsent(hd, node.data);

        min = Math.min(min, hd);
        max = Math.max(max, hd);

        if (node.left != null)
            q.offer(new Pair<>(node.left, hd - 1));
        if (node.right != null)
            q.offer(new Pair<>(node.right, hd + 1));
    }

    List<Integer> ans = new ArrayList<>();
    for (int i = min; i <= max; i++)
        ans.add(map.get(i));

    return ans;
}