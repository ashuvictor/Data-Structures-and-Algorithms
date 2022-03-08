
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*>st;
        TreeNode* curr;
        curr=root;
        while(curr!=NULL  or !st.empty()){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            ans.push_back(st.top()->val);
            curr=st.top()->right;
            st.pop();
        }
        return ans;
    }
};