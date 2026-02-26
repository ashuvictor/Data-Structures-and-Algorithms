import java.util.*;

class TrieNode {
    TrieNode[] children = new TrieNode[26];
    boolean isEnd = false;

    // Count children and return last index via array
    int countChildren(int[] index) {
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (children[i] != null) {
                count++;
                index[0] = i;
            }
        }
        return count;
    }
}

class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {
        TrieNode node = root;
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new TrieNode();
            }
            node = node.children[idx];
        }
        node.isEnd = true;
    }

    public String longestCommonPrefix() {
        StringBuilder prefix = new StringBuilder();
        TrieNode node = root;
        int[] index = new int[1]; // simulate pass-by-reference

        while (node != null) {
            if (node.isEnd) break;

            int count = node.countChildren(index);
            if (count != 1) break;

            node = node.children[index[0]];
            prefix.append((char) (index[0] + 'a'));
        }

        return prefix.toString();
    }
}

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";

        Trie trie = new Trie();
        for (String word : strs) {
            if (word.isEmpty()) return "";
            trie.insert(word);
        }

        return trie.longestCommonPrefix();
    }
}