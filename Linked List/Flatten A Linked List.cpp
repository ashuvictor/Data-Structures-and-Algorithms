


Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 Expected Time Complexity: O(N*N*M)
Expected Auxiliary Space: O(1)

 

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
 
//best
Node* merge(Node* left, Node* right) {
   
   if(left == NULL)
       return right;
   
   if(right == NULL)
       return left;
   
   Node* ans = NULL;
   
   if(left->data<=right->data){
       ans = left;
       ans->bottom=merge(left->bottom,right);
   }else{
       ans=right;
       ans->bottom=merge(left,right->bottom);
   }

   return ans;
   
}
Node *flatten(Node *root)
{
  if(root->next==NULL){
      return root;
  }
  Node * res = flatten(root->next);
  Node * ans = merge(root,res);
  ans->next=NULL;
  return ans;
}
// striver
Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}



//brute
     Node*middle(Node*root)
   {
       if(root==NULL || root->bottom==NULL)
       {
           return root;
       }
       Node*slow=root;
       Node*fast=root->bottom;
       while(fast!=NULL && fast->bottom!=NULL)
       {
           slow=slow->bottom;
           fast=fast->bottom->bottom;
       }
       return slow;
   }
   Node*merge(Node*left,Node*right)
   {
       if(left==NULL)
       {
           return right;
       }
       if(right==NULL)
       {
           return left;
       }
       Node*dummy=new Node(-1);
       Node*ans=dummy;
       while(left!=NULL && right!=NULL)
       {
           if(left->data<right->data)
           {
               ans->bottom=left;
               ans=left;
               left=left->bottom;
           }
           else{
               ans->bottom=right;
               ans=right;
               right=right->bottom;
               
           }
       }
       while(left!=NULL)
       {
           ans->bottom=left;
           ans=left;
           left=left->bottom;
       }
       while(right!=NULL)
       {
           ans->bottom=right;
           ans=right;
           right=right->bottom;
       }
       ans=dummy ->bottom;
       return ans;
   }
   Node* mergeSort(Node* root) {
       // your code here
       if(root==NULL || root->bottom==NULL)
       {
           return root;
       }
       Node*left=root;
       Node*mid=middle(root);
       
       Node*right=mid->bottom;
       mid->bottom=NULL;
       left=mergeSort(left);
       right=mergeSort(right);
       Node*ans=merge(left,right);
       return ans;
   }
Node *flatten(Node *root)
{
 Node*temp=root;
  
 while(temp!=NULL)
 {
     Node*next=temp->next;
     while(temp->bottom!=NULL)
     {
         temp=temp->bottom;
     }
     temp->bottom=next;
     temp=next;
     //now sort
  
 } 
  Node*newRoot=mergeSort(root);
    
  return newRoot;
}