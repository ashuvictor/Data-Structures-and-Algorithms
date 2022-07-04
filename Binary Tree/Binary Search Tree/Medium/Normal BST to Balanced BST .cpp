Given a Binary Search Tree, modify the given BST such that itis balanced and has minimum possible height.

Examples :

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30

Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   OR ..
    \          /                   \
     2        1                     4 

https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1/#

Node* BST(vector<int>InOrder,int n,int InOrderStart,int InOrderEnd)
{
  if(InOrderStart>InOrderEnd) return NULL;
  int mid=(InOrderStart+InOrderEnd)/2;
  Node* root=new Node(InOrder[mid]);
  root->left=BST(InOrder,n,InOrderStart,mid-1);
  root->right=BST(InOrder,n,mid+1,InOrderEnd);
  return root;
}

 

void InOrderTraversal(Node* root,vector<int> &InOrder)
{
   if(root==NULL) return;
   InOrderTraversal(root->left,InOrder);
   InOrder.push_back(root->data);
   InOrderTraversal(root->right,InOrder);
}

 

Node* buildBalancedTree(Node* root)
{
vector<int> InOrder;
InOrderTraversal(root,InOrder);
int n = InOrder.size();
Node* ans = BST(InOrder,n,0,n-1);
return ans;
}
