

https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13

class Solution
{
public:
    
  void solve(Node* root,int sum,int curr_level,int &maxsum,int &level){
      if(root==NULL)
      return;
      if(root->left==NULL and root->right==NULL and curr_level>=level and sum+root->data>maxsum){
          maxsum=sum+root->data;
          level=curr_level;
          return;
      }
      solve(root->left,sum+root->data,curr_level+1,maxsum,level);
      solve(root->right,sum+root->data,curr_level+1,maxsum,level);
      
  }
    int sumOfLongRootToLeafPath(Node *root)
    {int maxsum=0,level;
       solve(root,0,0,maxsum,level);
       return maxsum;
    }
};