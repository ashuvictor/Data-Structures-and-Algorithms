

Given a binary tree with a value associated with each node, we need to choose a subset of 
these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be
 directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*,int>mp;
    int getMaxSum(Node *root) 
    { //with node and without node
    // with node call the grandchildren //else children
        // Add your code here
        if(root==NULL)
        return 0;
       
        int withNode=root->data;
        if(root->left){
            withNode+=getMaxSum(root->left->left);
            withNode+=getMaxSum(root->left->right);
        }
        if(root->right){
            withNode+=getMaxSum(root->right->left);
            withNode+=getMaxSum(root->right->right);
        }
        int without=getMaxSum(root->left)+getMaxSum(root->right);
        return max(withNode,without);
    }
};



class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    unordered_map<Node*,int>mp;
    int getMaxSum(Node *root) 
    { //with node and without node
    // with node call the grandchildren //else children
        // Add your code here
        if(root==NULL)
        return 0;
        if(mp[root])
        return mp[root];
        int withNode=root->data;
        if(root->left){
            withNode+=getMaxSum(root->left->left);
            withNode+=getMaxSum(root->left->right);
        }
        if(root->right){
            withNode+=getMaxSum(root->right->left);
            withNode+=getMaxSum(root->right->right);
        }
        int without=getMaxSum(root->left)+getMaxSum(root->right);
        return mp[root]=max(withNode,without);
    }
};