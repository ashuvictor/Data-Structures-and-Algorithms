


You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges.
 Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.
Your task is to find the length of the shortest path between the ‘src’ and ‘dest’ vertex given to you in the graph. 
The graph may contain negatively weighted edges.

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