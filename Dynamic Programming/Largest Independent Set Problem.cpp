Given a Binary Tree, find size of the Largest Independent Set(LIS) in it.
 A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset. 

For example, consider the following binary tree. 
The largest independent set(LIS) is {10, 40, 60, 70, 80} and size of the LIS is 5.



int LISS(node *root)
{
    if (root == NULL)
    return 0;
 
    // Calculate size excluding the current node
    int size_excl = LISS(root->left) +
                    LISS(root->right);
 
    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
        size_incl += LISS(root->left->left) +
                     LISS(root->left->right);
    if (root->right)
        size_incl += LISS(root->right->left) +
                     LISS(root->right->right);
 
    // Return the maximum of two sizes
    return max(size_incl, size_excl);
}