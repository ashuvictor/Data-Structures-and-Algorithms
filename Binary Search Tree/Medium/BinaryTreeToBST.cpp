Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1

 https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1


class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder_tree(Node* root,vector<int>&v){
    if(!root){
        return;
    }
    inorder_tree(root->left,v);
    v.push_back(root->data);
    inorder_tree(root->right,v);
}
    void inorder_bst(Node* root,vector<int>v,int &i){
    if(!root){
        return;
    }
    inorder_bst(root->left,v,i);
 root->data=v[i];
    i++;
    inorder_bst(root->right,v,i);
}
    Node *binaryTreeToBST (Node *root)
    {
vector<int>v;
inorder_tree(root,v);
sort(v.begin(),v.end());
int i=0;
inorder_bst(root,v,i);
return root;


    }
};