

Given the root of a binary tree, return the reverse level order traversal of its nodes' values. The solution should consider the binary tree nodes level by level in bottom-up order from left to right, i.e., process all nodes of the last level first, followed by all nodes of the second last level, and so on.

Input:
		   1
		 /   \
		/	  \
	   2	   3
	  /		  / \
	 /	  	 /	 \
	4		5	  6
		   / \
		  /   \
		 7	   8

Output: [7, 8, 4, 5, 6, 2, 3, 1]

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

	vector<int> findReverseLevelOrderTraversal(Node* root)
	{
	
		// Write your code here...
		vector<int>ans;
		queue<Node*>q;
		q.push(root);
		while(!q.empty())
		{
			int sz=q.size();
			while(sz--){
				Node* temp=q.front();
				q.pop();
				ans.push_back(temp->data);
				if(temp->right)
				q.push(temp->right);
				if(temp->left)
				q.push(temp->left);
				
			}
		}
		reverse(ans.begin(),ans.end())
		return ans;
	}
};


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>result;
        stack<vector<int>>st;
        queue<TreeNode*>que;
        
        if(!root)
            return result;
        que.push(root);
        
        while(que.size()>0){
            vector<int>temp;
            int n=que.size();
            for(int i=0;i<n;i++){
                TreeNode * node= que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            if(temp.size()){
                st.push(temp);
            }
        }
        
        while(st.size()>0){
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};