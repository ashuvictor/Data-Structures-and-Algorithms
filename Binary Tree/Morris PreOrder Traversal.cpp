



void morrisTraversalPreorder(node* root)
{
    while (root)
    {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->left == NULL)
        {
            cout<<root->data<<" ";
            root = root->right;
        }
        else
        {
            // Find inorder predecessor
            node* current = root->left;
            while (current->right && current->right != root)
                current = current->right;
 
            // If the right child of inorder predecessor already points to
            // this node
            if (current->right == root)
            {
                current->right = NULL;
                root = root->right;
            }
 
            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else
            {
                cout<<root->data<<" ";
                current->right = root;
                root = root->left;
            }
        }
    }
}
 