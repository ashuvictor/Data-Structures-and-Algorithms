https://leetcode.com/problems/insert-into-a-binary-search-tree/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        
        if(val < root->val)
            root->left = insertIntoBST(root->left,val);
        else
            root->right = insertIntoBST(root->right,val);
        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
            return new TreeNode(val);
        TreeNode* curr;
        curr=root;
        while(true){
            if(curr->val<=val){
                if(curr->right!=NULL)
                    curr=curr->right;
                else{
                    curr->right=new TreeNode(val);break;
                }
            }
            else{
                if(curr->left!=NULL)
                {
                    curr=curr->left;
                }
                else{
                    curr->left=new TreeNode(val);break;
                }
            }
        }
        return root;
    }
};