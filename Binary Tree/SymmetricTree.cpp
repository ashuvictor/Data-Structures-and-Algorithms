bool isSymmetric(Node* X, Node* Y)
{
    // base case: if both trees are empty
    if (X == nullptr && Y == nullptr) {
        return true;
    }
 
    // return true if
    // 1. Both trees are non-empty, and
    // 2. The left subtree is the mirror of the right subtree, and
    // 3. The right subtree is the mirror of the left subtree
    return (X != nullptr && Y != nullptr) &&
        isSymmetric(X->left, Y->right) &&
        isSymmetric(X->right, Y->left);
}
 
// Function to check if a given binary tree has a symmetric structure or not
bool isSymmetric(Node* root)
{
    // base case
    if (root == nullptr) {
        return true;
    }
 
    // return true if left and right subtree mirror each other
    return isSymmetric(root->left, root->right);
}