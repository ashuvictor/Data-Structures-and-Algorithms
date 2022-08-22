


bool isHeap(struct Node* tree) {
       queue<struct Node*> q;
       q.push(tree);
       bool nullFounded=false;
       while(!q.empty()){
           Node* node = q.front();
           q.pop();
           
           if(node->left != NULL){
               if(nullFounded || node->data <= node->left->data) return false;
               q.push(node->left);
           }else nullFounded=true;
           
           if(node->right){
               if(nullFounded || node->data <= node->right->data) return false;
               q.push(node->right);
           }else nullFounded=true;
       }
       return true;
   }



   int countNodes(struct Node* root ){
   if(root == NULL){
       return 0;
   }
   
  int left = countNodes(root->left);
  int right = countNodes(root->right);
  
  return left + 1 + right;
  
}

 


bool isCompleteBTree(struct Node*  root , int n  , int index){
   
   if(root == NULL){
       return true;
   }
   
       if(index > n){
           return false;
       }
       
   bool left = isCompleteBTree(root->left , n , 2*index);
   bool right = isCompleteBTree(root->right , n , 2*index+1);
   
   return left && right;
   
}

 

 


bool isMaxHeap(struct Node*  root){
   
   if(root == NULL){
       return true;
   }
   
  
   if(root->left == NULL && root->right == NULL){
       return true;
       
   }
   
   
   if(root->right == NULL){
       return root->key >= root->left->key;
   }
   
   else{
       if(root->key >= root->left->key  && root->key >=root->right->key){
           
           bool left = isMaxHeap(root->left);
           bool right = isMaxHeap(root->right);
           
           
           return left && right;
           
       }
       
       else{
           return false;
       }
       
   }
   
   
   
}


                       bool isHeap(struct Node* root) {

 

  
   int n = countNodes(root);
   int i = 1;
   
   
   if( isCompleteBTree(root , n , i) && isMaxHeap(root) ){
       return true;
   }
   
   return false;
   
}