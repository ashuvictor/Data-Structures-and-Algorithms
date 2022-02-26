	void convertToMirror(Node* root)
	{
		// Write your code here...
		if(root==NULL)
		return;
		convertToMirror(root->left);
		convertToMirror(root->right);
		swap(root->left,root->right);
	}
};