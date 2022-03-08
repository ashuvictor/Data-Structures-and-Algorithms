https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    void solve(Node* root,int col,map<int,vector<int>>&m){
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            Node* node=q.front().first;
            int vertical=q.front().second;
            m[vertical].push_back(node->data);
            if(node->left)
            q.push({node->left,vertical-1});
            if(node->right)
            q.push({node->right,vertical+1});
            q.pop();
        }
    }
    vector<int> verticalOrder(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
        return ans;
        map<int,vector<int>>m;
        int col=0;
        solve(root,col,m);
        for(auto x:m){
            for(auto y:x.second)
            {
                ans.push_back(y);
            }
        }
        return ans;
    }
};

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode* node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left)
                todo.push({node->left,{x-1,y+1}});
            if(node->right)
                todo.push({node->right,{x+1,y+1}});
            
        }
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};