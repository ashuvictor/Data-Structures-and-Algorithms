Given a Binary Tree. Return true if, for every node X in the tree other than the leaves, its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.


Example 1:

Input:
    3
  /   \    
 1     2

Output: 1
Explanation:
The sum of left subtree and right subtree is
1 + 2 = 3, which is the value of the root node.
Therefore,the given binary tree is a sum tree.
https://practice.geeksforgeeks.org/problems/sum-tree/1#
class Solution
{
    public:
    int  solve(Node* root,bool &flag){
        if(root==NULL)
        return 0;
        if(root->left==NULL and root->right==NULL)
        return root->data;
        int left=solve(root->left,flag);
        int right=solve(root->right,flag);
        if(root->data!=(left+right))
        flag=false;
        return left+right+root->data;
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         bool flag=true;
         int x=solve(root,flag);
         return flag;
    }
};