// https://leetcode.com/problems/maximum-width-of-binary-tree/
// // first approach calculae height 
// // 2^(h-1)

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int res = 1;
        queue<pair<TreeNode*, int>> q;
        
        // I am using intialising list
        q.push({root, 0});      // also can use make_pair
        
        while(!q.empty())
        {
            int cnt = q.size();
            // start is the index of root node for first level
            int start = q.front().second;
            int end = q.back().second;
            
            res = max(res,end-start + 1);
            
            for(int i = 0; i <cnt; ++i)
            {
                pair<TreeNode*, int> p = q.front();
                // we will use it while inserting it children
                // left child will be 2 * idx + 1;
                // right chils will be 2 * idx + 2;
                int idx = p.second - start;
                
                q.pop();
                
                // if  left child exist
                if(p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});
                
                // if right child exist
                if(p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }
        
        return res;
        
    }
};
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