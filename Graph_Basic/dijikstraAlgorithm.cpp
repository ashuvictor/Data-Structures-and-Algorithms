 /*Implementing Dijkstra Algorithm
 https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/?page=1&difficulty[]=1&category[]=Graph&sortBy=submissions
 */
vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    int V = adj.size();
    // Initialize distance vector and set source distance to 0
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Priority queue to pick the vertex with the smallest distance
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int curr_node = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();

        // Optional: Skip processing if we have an outdated distance
        if (curr_dist > dist[curr_node])
            continue;

        for (auto x : adj[curr_node]) {
            // Use .first and .second to access the pair's elements
            int next_node = x.first;
            int weight = x.second;
            if (curr_dist + weight < dist[next_node]) {
                dist[next_node] = curr_dist + weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return dist;
}





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


vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Using a set to store pairs of {distance, vertex}
    set<pair<int,int>> st;
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    st.insert({0, S});
    
    while (!st.empty()){
        // Get the vertex with the smallest distance
        auto it = st.begin();
        int curr_dist = it->first;
        int curr_node = it->second;
        st.erase(it);
        
        // Check all adjacent nodes of the current node
        for(auto x : adj[curr_node]){
            int next_node = x[0];
            int weight = x[1];
            if(curr_dist + weight < dist[next_node]){
                // If next_node already has a distance value, remove it from the set
                if(dist[next_node] != INT_MAX) {
                    st.erase({dist[next_node], next_node});
                }
                // Update distance and insert new pair into the set
                dist[next_node] = curr_dist + weight;
                st.insert({dist[next_node], next_node});
            }
        }
    }
    return dist;
}
