https://leetcode.com/problems/delete-node-in-a-bst/

class Solution {
public:
    TreeNode* inorderSucc(TreeNode* root)
    {
        TreeNode* p;
        p=root->right;
        while(p->left){
            p=p->left;
        }
        return p;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
         if(key>root->val)
            root->right=deleteNode(root->right,key);
        else if(key<root->val)
          root->left= deleteNode(root->left,key);
        else{
            if(root->right==NULL){
                TreeNode* temp;
                temp=root->left;
                delete(root);
                return temp;
            }
            else if(root->left==NULL){
                TreeNode* temp;
                temp=root->right;
                delete(root);
                return temp;
            }
            else {
                TreeNode* temp;
                temp= inorderSucc(root);
                swap(root->val,temp->val);
                root->right=deleteNode(root->right,key);
            }
        }
        return root;
    }
};