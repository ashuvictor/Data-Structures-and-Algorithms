/*Image Multiplication
https://practice.geeksforgeeks.org/problems/image-multiplication0627/1#
You are given a binary tree. Your task is pretty straightforward. 
You have to find the sum of the product of each node and its mirror image (The mirror of a node is a node which exists at the mirror position of the node in opposite subtree at the root.). Don’t take into account a pair more than once. 
The root node is the mirror image of itself.

*/
class Solution
{
    public:
    int mod=1e9;
    void helper(Node* root1,Node* root2,long long &mul){
        if(!root1 or !root2)
        return;
        mul+=((root1->data)*(root2->data))%mod;
        helper(root1->left,root2->right,mul);
        helper(root1->right,root2->left,mul);
    }
    long long imgMultiply(Node *root)
    {
        long long mul=root->data*root->data;
        helper(root->left,root->right,mul);
        return mul%mod;
    }
};