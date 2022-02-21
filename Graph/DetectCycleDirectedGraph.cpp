/* CYCLE IN DIRECTED GRAPH
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/?page=1&difficulty[]=1&category[]=Graph&sortBy=submissions
*/
bool isCyclic_util(vector<int> adj[], vector<bool> visited, int curr)
{
    if(visited[curr]==true)
        return true;
    
    visited[curr] = true;
    bool FLAG = false;
    for(int i=0;i<adj[curr].size();++i)
    {
        FLAG = isCyclic_util(adj, visited, adj[curr][i]);
        if(FLAG==true)
            return true;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
   vector<bool> visited(V,false);
   bool FLAG = false;
   for(int i=0;i<V;++i)
   {
           visited[i] = true;
           for(int j=0;j<adj[i].size();++j)
           {
               FLAG = isCyclic_util(adj,visited,adj[i][j]);
               if(FLAG==true)
                   return true;
           }
           visited[i] = false;
   }
   return false;
}

/* BFS KAHN ALGORITHM*/
class Solution {
public:
	bool isCyclic(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++; 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false; 
	    return true; 
	}
};
