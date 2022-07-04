
https://leetcode.com/problems/n-ary-tree-preorder-traversal/
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root,vector<int>&ans)
    {
        for(Node* x:root->children)
            solve(x,ans);
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        solve(root,ans);
        return ans;
    }
};

class Solution {
public:
    void solve(Node* root,vector<int>&ans)
    {
        ans.push_back(root->val);
        for(Node* x:root->children)
            solve(x,ans);
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        solve(root,ans);
        return ans;
    }
};