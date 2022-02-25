class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp;
            temp=st.top();
            ans.push_back(temp->val);
            st.pop();
            if(temp->left)
                st.push(temp->left);
            if(temp->right)
                st.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};