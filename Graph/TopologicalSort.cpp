/*  TOPO SORT
https://practice.geeksforgeeks.org/problems/topological-sort/1 */
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int>q;
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            indegree[x]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int temp=q.front();
	        q.pop();ans.push_back(temp);
	        for(auto x:adj[temp]){
	            indegree[x]--;
	            if(indegree[x]==0)
	            q.push(x);
	        }
	    }
	    return ans;
	}
};

DFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int V,vector<int>adj[],vector<bool>&visited,stack<int> &st,int i){
	    visited[i]=true;
	    for(auto e:adj[i]){
	        if(visited[e]==false)
	        dfs(V,adj,visited,st,e);
	    }
	    st.push(i);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool>visited(V,false);
	    vector<int>ans;
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(visited[i]==false)
	        dfs(V,adj,visited,st,i);
	    }
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};