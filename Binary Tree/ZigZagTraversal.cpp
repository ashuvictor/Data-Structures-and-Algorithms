https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int sz=q.size();
            vector<int>row;
            for(int i=0;i<sz;i++){
                TreeNode* temp;
                temp=q.front();
                q.pop();
                row.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(flag)
                reverse(row.begin(),row.end());
            flag=!flag;
            res.push_back(row);
        }
        return res;
    }
};