class Solution {
public:
 
    vector<int> preorderTraversal(TreeNode* root) {
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
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return ans;
    }
};