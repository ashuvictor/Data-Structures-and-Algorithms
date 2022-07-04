Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.


Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)

void inorder(Node* root,map<int,int> &m){
       if(!root)return;
       inorder(root->left,m);
       m[root->data]++;
       inorder(root->right,m);
   }
   int countPairs(Node* root1, Node* root2, int x)
   {
       map<int,int> m,p;
       inorder(root1,m);
       inorder(root2,p);
       int c=0;
       for(auto it:m){
           int y=x-it.first;
           if(p[y]>0)c++;
       }
       return c;
   }

   //Time complexity O(n*k)

//Space Complexity O(1) -→optimized   

   int cnt=0;
   bool search(Node* root,int key){
       if(root==NULL)
           return false;
       if(root->data==key)
           return true;
       else if(root->data>key)
           return search(root->left,key);
       else
           return search(root->right,key);
   }
   void inorder(Node* root1,Node* root2,int k){
       if(root1==NULL)
           return;
       inorder(root1->left,root2,k);
       if(search(root2,k-root1->data))
           cnt++;
       inorder(root1->right,root2,k);
   }
   int countPairs(Node* root1, Node* root2, int x){
       inorder(root1,root2,x);
       return cnt;
   }