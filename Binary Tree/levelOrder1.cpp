https://techiedelight.com/practice/?problem=LevelOrderTraversal

vector<int> findLevelOrderTraversal(Node* root)
	{
		// Write your code here...
		vector<int>ans;
		if(root==NULL)
		return ans;
		queue<Node*>q;
		q.push(root);
		while(!q.empty()){
			int sz=q.size();
			Node* temp;
			while(sz--){
				temp=q.front();
				q.pop();
				ans.push_back(temp->data);
				if(temp->left)
				q.push(temp->left);
				if(temp->right)
				q.push(temp->right);
			}
		}
		return ans;
	
	}
};