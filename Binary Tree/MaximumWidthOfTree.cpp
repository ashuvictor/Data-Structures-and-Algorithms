https://leetcode.com/problems/maximum-width-of-binary-tree/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            int mini=q.front().second;
            int first,last;
             for(int i=0;i<sz;i++){
                int id=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)
                    first=id;
                 if(i==sz-1)
                     last=id;
                 if(node->left)
                     q.push({node->left,(long long int)id*2+1});
                 if(node->right)
                     q.push({node->right,(long long int)id*2+2});
                 
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};