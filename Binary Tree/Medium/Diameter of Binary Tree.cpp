
https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
The diameter of a tree (sometimes called the width) is the number of nodes 
on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(Node* root){
        if(root==NULL)
        return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameter(Node* root) {
        if(root==NULL)
        return 0;
        int op1=height(root->left)+height(root->right)+1;
        int op2=diameter(root->left);
        int op3=diameter(root->right);
        return max(op1,max(op2,op3));
    }
};

or 
class Solution {
  public:
  int dia;
    // Function to return the diameter of a Binary Tree.
      int height(Node* root){
       if(root==NULL)
       return 0;
       int lh=height(root->left);
       int rh=height(root->right);
       dia=max(dia,lh+rh+1);
       return 1+max(lh,rh);
           
       }
   int diameter(Node* root) {
        // Your code here
         dia=0;
        height(root);
        return dia;
    }
};
 public:
    // Function to return the diameter of a Binary Tree.
    
    pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }
    int diameter(Node* root) {
    
        return diameterFast(root).first;
        
    }

 https://leetcode.com/problems/diameter-of-binary-tree/


class Solution {
public:
    int solve(TreeNode* root,int &diameter){
        if(root==NULL)
            return 0;
        int leftd=solve(root->left,diameter);
        int rightd=solve(root->right,diameter);
        diameter=max(leftd+rightd,diameter);
        return max(leftd,rightd)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int diameter=0;
        solve(root,diameter);
        return diameter;
    }
};