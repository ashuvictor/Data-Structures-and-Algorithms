Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Example 2:

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5
https://practice.geeksforgeeks.org/problems/burning-tree/1#



class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*>parent;
        queue<Node*>q;
        q.push(root);
        parent[root]=NULL;
        Node* targetNode=NULL;
        unordered_set<Node*>vis;
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            vis.insert(node);
            if(node->data==target)
            targetNode=node;
            if(node->left)
            {
                q.push(node->left);
                parent[node->left]=node;
            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
        }
        q.push(targetNode);
        int timer=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                Node* curr=q.front();
                q.pop();
                if(curr->left and vis.find(curr->left)!=vis.end()){
                    q.push(curr->left);
                    vis.erase(curr->left);
                }
                if(curr->right and vis.find(curr->right)!=vis.end())
                {
                    q.push(curr->right);
                    vis.erase(curr->right);
                }
                if(parent[curr] and vis.find(parent[curr])!=vis.end())
                {
                    q.push(parent[curr]);
                    vis.erase(parent[curr]);
                }
            }
            if(!q.empty())
            timer++;
        }
        return timer;
    }
};