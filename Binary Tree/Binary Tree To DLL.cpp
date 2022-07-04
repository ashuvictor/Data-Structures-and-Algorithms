
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous 
and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree.
 The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

void helper(Node *root,Node *&head,Node *&pre){
       if(!root)
           return;
       helper(root->left,head,pre);
       if(!pre){
           head = root;
       }else{
           root->left = pre;
           pre->right = root;
       }
       pre = root;
       
       helper(root->right,head,pre);
   }
   Node * bToDLL(Node *root)
   {
       Node *head=NULL,*pre = NULL;
       helper(root,head,pre);
       return head;
       // your code here
   }