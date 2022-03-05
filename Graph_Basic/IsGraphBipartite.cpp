/*
 Is Graph Bipartite?
 https://leetcode.com/problems/is-graph-bipartite/
*/
class Solution {
public:
   bool bipartite(int src,vector<vector<int>>&graph,vector<int>&color){
       queue<int>q;
       q.push(src);
       color[src]=1;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           for(auto it:graph[node]){
               if(color[it]==-1)
               {color[it]=1-color[node];q.push(it);}
               else if(color[it]==color[node])
                   return false;
           }
       }
       return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bipartite(i,graph,color))
                    return false;
            }
        }
        return true;
        
    }
};
// dfs
    bool bipartite_dfs(int src,vector<vector<int>>&graph,vector<int>&color){
     for(auto nbr:graph[src]){
         if(color[nbr]==-1)
         {
             color[nbr]=1-color[src];
         
         if(!bipartite_dfs(nbr,graph,color))
             return false;
         }
         else if(color[nbr]==color[src])
             return false;
     }
        return true;
    }