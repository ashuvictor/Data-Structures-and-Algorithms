An edge in an undirected connected graph is a bridge if removing it disconnects the graph.
 For a disconnected undirected graph, definition is similar,
  a bridge is an edge removing which increases number of disconnected components. 

Naive Approach: A simple approach is to one by one remove all edges and see if removal of an edge causes disconnected graph. Following are steps of simple approach for connected graph.

For every edge (u, v), do following :

Remove (u, v) from graph 
See if the graph remains connected (We can either use BFS or DFS) 
Add (u, v) back to the graph.
Time Complexity: O(E*(V+E)) for a graph represented using adjacency list.

Efficient Approach:  The idea is similar to O(V+E) algorithm for Articulation Points. We do DFS traversal of the given graph. In DFS tree an edge (u, v) (u is parent of v in DFS tree) is bridge 
if there does not exist any other alternative to reach u or an ancestor of u from subtree rooted with v. 


Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph. A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).
For Example :
If the given graph is :



disc[]-time at which it is covered
low[]-lowest possible disc time
parent[]-keep track of parents
visited[]-



//if you find a back edge update it the lowest possible time 
// if neighbour ==parent then ignore it
low[neighbour]>disc[node]
bridge is there


#include<bits/stdc++.h>
void dfs(int node,int parent,int &timer,vector<int>&disc,vector<int>&low, vector<vector<int>>&result, unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited)
{
    visited[node]=true;
    disc[node]=low[node]=timer++;
    for(auto nbr:adj[node])
    {
        if(nbr==parent)
            continue;
        if(!visited[nbr])
        {
            dfs(nbr,node,timer,disc,low,result,adj,visited);
            low[node]=min(low[node],low[nbr]);
            //check for bridge
            if(low[nbr]>disc[node])
            {
                vector<int>ans;
                ans.push_back(nbr);
                ans.push_back(node);
                result.push_back(ans);
            }
        }
        else
        {
            //back edge
            low[node]=min(low[node],disc[nbr]);
        }
    }
    
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
//adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    int timer=0;
    vector<int>disc(v);
    vector<int>low(v);
    int parent=-1;
    unordered_map<int,bool>visited;
    for(int i=0;i<v;i++){
        disc[i]=-1;
        low[i]=-1;
    }
    //dfs
    vector<vector<int>>result;
    for(int i=0;i<v;i++){
        if(!visited[i])
        {
            dfs(i,parent,timer,disc,low,result,adj,visited);
        }
    }


return result;






}