



Minimum element in BST 

int minValue(Node* root) {
    // Code here
    if(root==NULL)
    return -1;
    if(root->left!=NULL)
    return minValue(root->left);
    else
    return root->data;
}