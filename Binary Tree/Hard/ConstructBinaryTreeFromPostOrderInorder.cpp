Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, 
construct and return the binary tree.
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution {
public:
	TreeNode* build(vector<int>&inorder, int is, int ie, vector<int>&postorder, int ps, int pe, map<int,int>& mp){
        if(is>ie or ps>pe)
            return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot=mp[postorder[pe]];
        int leftNodes=inroot-is;
        root->left = build(inorder, is, inroot-1, postorder, ps, ps+leftNodes-1, mp);
		root->right = build(inorder, inroot+1, ie, postorder, ps+leftNodes, pe-1, mp);

		return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(inorder,0,n-1,postorder,0,n-1,mp);
    }
};


