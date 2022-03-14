/* bst from preorder
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
three ways 
sorted form is inorder use the technique
or construct tree using preorder and inorder a
and another using this technique
*/


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};