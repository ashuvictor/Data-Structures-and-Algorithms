
Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.


void count_nodes(Node* root,int &c){
    if(!root) return;
    count_nodes(root->left,c);
    c++;
    count_nodes(root->right,c);
}

void func(Node* root,Node* &cur,Node* &prev,int &c,int k,int &f){
    if(!root) return;
    func(root->left,cur,prev,c,k,f);
    if(prev==NULL){
        prev = root;
        c++;
    }
    else if(c==k){
        c++;
        cur = root;
        f = 1;
        return;
    }
    else if(f==0){
        c++;
        prev = root;
    }
    func(root->right,cur,prev,c,k,f);
}

float findMedian(struct Node *root)
{
      //Code here
      int n = 0;
      count_nodes(root,n);
      Node* cur = NULL;
      Node* prev = NULL;
      int c = 1;
      int x = (n/2)+1;
      int f = 0;
      func(root,cur,prev,c,x,f);
      if(n&1){
          float ans = (cur->data)*1.0;
          return ans;
      }
      else {
          float ans = ((cur->data+prev->data)*1.0)/(2*1.0);
          return ans;
      }
      
}
