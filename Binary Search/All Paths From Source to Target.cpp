Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 


 https://leetcode.com/problems/all-paths-from-source-to-target/

 class Solution {
public:
    void solve(int src,vector<vector<int>>&graph,vector<int>&path,vector<vector<int>>&ans,vector<bool>&visited)
    {
        visited[src]=true;
        if(src==graph.size()-1){
           
            ans.push_back(path);
            return;
        }
        for(auto v:graph[src]){
            if(!visited[v])
            {
                path.push_back(v);
                solve(v,graph,path,ans,visited);
                visited[v]=false;
                path.pop_back();
            }
        }
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        vector<vector<int>>ans;
        path.push_back(0);
        vector<bool>visited(graph.size(),false);
        solve(0,graph,path,ans,visited);
        return ans;
    }
};