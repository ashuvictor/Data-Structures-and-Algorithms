https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

The values smaller than root go to the left side
The values greater and equal to the root go to the right side
Example 1:

Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the
range



int getCount(Node *root, int l, int h)
{
 if(!root)
 return 0;
 if(root->data>=l and root->data<=h)
 return 1+getCount(root->left,l,h)+getCount(root->right,l,h);
 if(root->data>h)
 return getCount(root->left,l,h);
 else
 return getCount(root->right,l,h);
}
