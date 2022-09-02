/*

Given the root of a binary tree, in-place replace each node's value to the sum of all elements present in its left and right subtree. You may assume the value of an empty child node to be 0.

Input:

	   1
	 /   \
	/	  \
   2	   3

Output:

	   5
	 /   \
	/	  \
   0	   0


Input:

	   1
	 /	 \
	/	  \
   /	   \
  2			3
   \	   / \
	\	  /	  \
	 4   5	   6
		/ \
	   /   \
	  7		8

Output:

	   35
	 /	  \
	/	   \
   /		\
  4			26
   \	   /  \
	\	  /	   \
	 0   15		0
		/  \
	   /	\
	  0		 0

*/

class Solution
{
public:

	/*
		A binary tree node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/
int solve(Node* root){
	if(root==NULL)
	return 0;
	int leftSum=solve(root->left);
	int rightSum=solve(root->right);
	int val=root->data;
	root->data=leftSum+rightSum;
	return val+root->data;
}
	void transform(Node* root)
	{
		// Write your code here...
		solve(root);
	}
};
