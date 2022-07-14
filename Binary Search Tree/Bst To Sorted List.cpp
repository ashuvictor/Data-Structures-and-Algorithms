



void inorder(node* curr, node*& prev)
{
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}
 
// Function to flatten binary tree using
// level order traversal
node* flatten(node* parent)
{
    // Dummy node
    node* dummy = new node(-1);
 
    // Pointer to previous element
    node* prev = dummy;
 
    // Calling in-order traversal
    inorder(parent, prev);
 
    prev->left = NULL;
    prev->right = NULL;
    node* ret = dummy->right;
 
    // Delete dummy node
    delete dummy;
    return ret;
}