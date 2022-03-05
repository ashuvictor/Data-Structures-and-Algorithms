 /*  CYCLE IN UNDIRECTED GRAPH
 https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/?page=1&difficulty[]=1&category[]=Graph&sortBy=submissions#
 */
 bool checkForCycleDFS(int node,int parent,vector<int> & visited ,vector<int> adj[])
   {
       visited[node]=1;
       for(auto u:adj[node])
       {
           if(visited[u]==0)
           {
               if(checkForCycleDFS(u,node,visited,adj)) 
                   return true;  
           }else if(u!=parent) 
                   return true;
       }
       return false;
   }
   bool checkForCycleBFS(int s,vector<int> &visited,vector<int> adj[])
   {
       queue<pair<int,int>> q;
       q.push({s,-1});
       visited[s]=1;
       while(!q.empty())
       {
           int node=q.front().first;
           int parent=q.front().second;
           q.pop();
           for(auto u:adj[node])
           {
               if(visited[u]==0)
               {
                   q.push({u,node});
                   visited[u]=1;
               }else if(parent!=u)
               {
                   return true;
               }
           }
       }
       return false;
   }
   bool isCycle(int V, vector<int> adj[]) {
       // Code here
       vector<int> visited(V,0);
       for(int i=0;i<V;i++)
       {
           if(visited[i]==0)
           {
               // if(checkForCycleDFS(i,-1,visited,adj))
               //     return true;
               if(checkForCycleBFS(i,visited,adj))
                   return true;
           }
       }
       return false;
   }