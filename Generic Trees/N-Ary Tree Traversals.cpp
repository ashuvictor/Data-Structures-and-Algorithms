
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


#include <iostream>
#include <vector>
using namespace std;

// Definition of the tree node for an n-ary tree.
class Node {
public:
    int val;                      // The value/data held in the node.
    vector<Node*> children;       // A list of pointers to the node's children.

    // Constructor to initialize the node with a value.
    Node(int x) : val(x) {}
};

// Function to find the Lowest Common Ancestor (LCA) of two nodes p and q in an n-ary tree.
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    // Base Case 1: If the current node is null, return null.
    if (root == nullptr) {
        return nullptr;
    }
    
    // Base Case 2: If the current node matches either p or q, return the current node.
    if (root == p || root == q) {
        return root;
    }
    
    int count = 0;    // Counter to track how many children return a non-null result.
    Node* temp = nullptr; // Temporary pointer to hold the last non-null result.
    
    // Recursively traverse every child of the current node.
    for (Node* child : root->children) {
        Node* res = lowestCommonAncestor(child, p, q);
        if (res != nullptr) {  // If a child returns a non-null value...
            count++;         // Increment our count.
            temp = res;      // Store the result.
        }
    }
    
    // If two or more children returned non-null, it means p and q are found in different subtrees.
    // Hence, the current node is their lowest common ancestor.
    if (count >= 2) {
        return root;
    }
    
    // Otherwise, if only one child returned non-null, propagate that result up.
    return temp;
}

int main() {
    // Create the root of the tree.
    Node* root = new Node(1);
    
    // Create children for the root.
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children.push_back(child3);
    
    // Add children to child1 (for example, nodes with values 5 and 6).
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    child1->children.push_back(node5);
    child1->children.push_back(node6);
    
    // Add a child to child2 (node with value 7).
    Node* node7 = new Node(7);
    child2->children.push_back(node7);
    
    // Add children to child3 (nodes with values 8 and 9).
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    child3->children.push_back(node8);
    child3->children.push_back(node9);
    
    // Example: Find the LCA of node5 and node6 (both children of node2).
    Node* lca = lowestCommonAncestor(root, node5, node6);
    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }
    
    // Note: In a complete program, you should deallocate the allocated memory.
    // For simplicity and brevity, cleanup is omitted here.

    return 0;
}
