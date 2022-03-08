Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.


https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        map<TreeNode*,TreeNode*>parent;
        map<TreeNode*,bool>visited;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp;
            temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                parent[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent[temp->right]=temp;
            }
        }
        int distance=0;
        vector<int>ans;
        q.push(target);
        visited[target]=true;
        while(!q.empty()){
            int s=q.size();
            if(distance++==k)
                break;
            while(s--){
                TreeNode* temp;
                temp=q.front();
                q.pop();
                if(temp->left and !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right and !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                    
                }
                if(parent[temp] and !visited[parent[temp]])
                {
                    q.push(parent[temp]);
                    visited[parent[temp]]=true;
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};