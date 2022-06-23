



1. Initialize current as root 
2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Find rightmost node in current left subtree OR
              node whose right child == current.
         If we found right child == current
             a) Update the right child as NULL of that node whose right child is current
             b) Print current’s data
             c) Go to the right, i.e. current = current->right
         Else
             a) Make current as the right child of that rightmost 
                node we found; and 
             b) Go to this left child, i.e., current = current->left


Case 1: When the current node has no left subtree. In this scenario, there is nothing to be traversed on the left side, so we simply print the value of the current node and move to the right of the current node.
Case 2: When there is a left subtree and the right-most child of this left subtree is pointing to null. In this case we need to set the right-most child to point to the current node, instead of NULL and move to the left of the current node.
Case 3: When there is a left subtree and the right-most child of this left-subtree is already pointing to the current node. In this case we know that the left subtree is already visited so we need to print the value of the current node and move to the right of the current node.
Note: Case 3 is very important as we need to remove the new links added to restore the original tree. 

To summarize, at a node whether we have to move left or right is determined whether the node has a left subtree. If it doesn’t we move to the right. If there is a left subtree then we see its rightmost child. If the rightmost child is pointing to NULL, we move the current node to its left. If the rightmost child is already pointing towards the current node, we remove that link and move to the right of the current node. 
We will stop the execution when the current points to null and we have traversed the whole tree.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val);
                curr=curr->right;
                
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right and prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr; //creating a thread
                    curr=curr->left;
                }
                else
                { prev->right=NULL;//delete thread
                 inorder.push_back(curr->val);//came back and u will take the value
                 curr=curr->right;
                 
                    
                }
            }
        }
        
        
        
        
        
        return inorder;
        
    }
};