


Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.

Example 1:

Input:
        1
      /   \
     4     4
   /   \
  6     8
Output: 1
Explanation: There's no sub-tree with size
greater than 1 which forms a BST. All the
leaf Nodes are the BSTs with size equal
to 1.
//approach 1
every nodes check whether is a bst or not 
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> solve(Node* root){
        if(!root)
        return {1,0,INT_MAX,INT_MIN};
        if(root->left==NULL and root->right==NULL)
        return {1,1,root->data,root->data};
        vector<int>l=solve(root->left);
        vector<int>r=solve(root->right);
        if(l[0] and r[0])
        {
            if(root->data>l[3] and root->data<r[2])
            {
                int x=l[2];
                int y=r[3];
                if(x==INT_MAX)
                x=root->data;
                if(y==INT_MIN)
                y=root->data;
                return {1,l[1]+r[1]+1,x,y};
            }
        }
        return {0,max(l[1],r[1]),0,0};
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	vector<int>ans=solve(root);
    	return ans[1];
    }
};


