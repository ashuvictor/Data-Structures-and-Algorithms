


You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges.
 Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
Your task is to find the length of the shortest path between the ‘src’ and ‘dest’ vertex given to you in the graph. 
The graph may contain negatively weighted edges.
Explanation
Initialization:
The dist vector is initialized with a value of 100000000 (i.e., 10^8) for all vertices, and the source vertex src is set to 0.

Edge Relaxation:
The algorithm relaxes all edges V-1 times. For each edge, if the current distance to u plus the edge weight is smaller than the current distance to v, then update the distance to v.

Negative Cycle Detection:
After V-1 relaxations, the algorithm checks all edges one more time. If any edge can still be relaxed, it means there is a negative weight cycle reachable from the source, and the function returns {-1}.

Return Value:
If no negative cycle is found, the function returns the vector dist, which contains the shortest distances from src to every vertex, with unreachable vertices remaining at 100000000.

This solution meets the problem requirements effectively.








class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int INF = 100000000; // Using 10^8 as the unreachable distance
        vector<int> dist(V, INF);
        dist[src] = 0;
        
        // Relax all edges V-1 times.
        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                // If u is reachable and we found a shorter path to v
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        
        // Check for negative-weight cycles.
        // If we can still relax any edge, then a negative cycle exists.
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                return {-1}; // Negative cycle detected.
            }
        }
        
        return dist;
    }
};


























int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dist[u]!=1e9 and dist[u]+wt<dist[v])
            {
                dist[v]=wt+dist[u];
            }
        }
    }
    bool flag=false;
    //negative cycle
    for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dist[u]!=1e9 and dist[u]+wt<dist[v])
            {  flag=true;
               
            }
        }
    if(flag==false)
        return dist[dest];
    return -1;
    
}
