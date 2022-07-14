


VISIT ALL NODES WHEN STARTING FROM ANYONE
SORT ALL NODES ON THEIR FININSHING TIME
TRANSPOSE OF GRAPH
APPLY DFS



#include<bits/stdc++.h>
void revDfs(int node,unordered_map<int,bool>&visited, unordered_map<int,list<int>>&transpose)
{
    visited[node]=true;
    for(auto nbr :transpose[node])
    {
        if(!visited[nbr])
        {
            revDfs(nbr,visited,transpose);
        }
    }
}
void dfs(int node,unordered_map<int,bool>&visited,stack<int>&st, unordered_map<int,list<int>>&adj)
{
    visited[node]=true;
    for(auto nbr:adj[node])
    {
        if(!visited[nbr])
        {
            dfs(nbr,visited,st,adj);
        }
    }
    st.push(node);
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    stack<int>st;
    unordered_map<int,bool>visited;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,st,adj);
        }
    }
    //create a transpose graph
    unordered_map<int,list<int>>transpose;
    for(int i=0;i<v;i++){
        visited[i]=0;
        for(auto nbr:adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    //dfs call for solution
    int ans=0;
    while(!st.empty())
    {
        int top=st.top();
        st.pop();
        if(!visited[top])
        {
            ans++;
            revDfs(top,visited,transpose);
        }
    }
    return ans;
    
    
    
}