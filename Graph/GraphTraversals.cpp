/*  BFS OF GRAPH  
https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
      vector<int>ans;
      vector<bool>visited(V+1,false);
      queue<int>q;
      q.push(0);
      visited[0]=true;
      while(!q.empty()){
          int node=q.front();
          q.pop();
          ans.push_back(node);
          for(auto child:adj[node]){
              if(!visited[child]){
                  q.push(child);
                 visited[child]=true;
              }
          }
      }
      return ans;
    }
};
/*DFS TRAVERSAL 
https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/
    void dfs(int i,vector<int>adj[], bool visited[],vector<int>&ans)
{  visited[i]=true;
ans.push_back(i);
for(auto nbr:adj[i]){
    if(!visited[nbr]){
        dfs(nbr,adj,visited,ans);
    }
}
    
}
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        bool visited[V+1]={false};
        
       
        for(int i=0;i<V;i++){
            if(!visited[i])
            dfs(i,adj,visited,ans);
        }
    return ans;}
};