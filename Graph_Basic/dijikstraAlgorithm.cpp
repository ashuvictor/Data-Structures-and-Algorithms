 /*Implementing Dijkstra Algorithm
 https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?page=1&difficulty[]=1&category[]=Graph&sortBy=submissions
 */
  vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int curr_dist=pq.top().first;
            int curr_node=pq.top().second;
            pq.pop();
            for(auto x:adj[curr_node]){
                if(curr_dist+x[1]<dist[x[0]]){
                    dist[x[0]]=curr_dist+x[1];
                    pq.push({dist[x[0]],x[0]});
                }
            }
        }
        return dist;
    }
};