TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
    return A;
    TreeNode* root=A;
    stack<TreeNode*>st;
    st.push(A);
    while(!st.empty())
    {
        TreeNode* curr=st.top();
        st.pop();
        if(curr->right)
        st.push(curr->right);
        if(curr->left)
        st.push(curr->left);
        if(!st.empty())
        curr->right=st.top();
        curr->left=NULL;
    }
    return root;
    
}
