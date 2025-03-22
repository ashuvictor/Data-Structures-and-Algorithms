#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }

    // Count how many children this node has
    int countChildren(int& index) {
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (children[i]) {
                count++;
                index = i;
            }
        }
        return count;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    string longestCommonPrefix() {
        string prefix = "";
        TrieNode* node = root;
        int index;

        while (node) {
            if (node->isEnd) break;
            int count = node->countChildren(index);
            if (count != 1) break;

            // Append the only child character
            node = node->children[index];
            prefix += (char)(index + 'a');
        }

        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie trie;
        for (const string& word : strs) {
            if (word.empty()) return "";
            trie.insert(word);
        }

        return trie.longestCommonPrefix();
    }
};
