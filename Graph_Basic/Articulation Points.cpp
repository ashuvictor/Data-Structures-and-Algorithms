For a connected undirected graph, an articulation point or a cut vertex is a vertex in the graph 
removing which disconnects the graph.
For a disconnected undirected graph, an articulation point or a cut vertex is a vertex removing 
which increases the number of connected 
components.



Idea: A simple method is to remove all vertices one by one and see if it causes the graph to become disconnected.
 

Algorithm:

Loop around all the vertices.
Do the following for each vertex v
a) Remove v from the graph.

b) Check if the graph is still connected (we can use BFS or DFS to check that)

c) Add v to the graph again.

 

Time Complexity: O(V*(V+E)). For every v, BFS/DFS will take O(V+E) time to check for the graph's connectivity. Therefore, O(V*(V+E)) is the time complexity.


The idea is to use DFS and find the articulation points simultaneously with some extra coding.
 As DFS takes O(V+E) time
 therefore the time complexity of this approach will be O(V+E).


 In the DFS tree, a vertex u is articulation point if any of the following conditions is true:

u is the root of the DFS tree, and it has at least two children.


 u is not the root of the DFS tree, and it has a child v such that no vertex in the subtree rooted with v has a back edge to any of u's ancestors in the DFS tree.


 #include <bits/stdc++.h>
using namespace std;

// A function to add edges in the graph.
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void APUtil(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &disc, vector<int> &low, int &time, int u, int parent, vector<bool> &AP)
{
    // To count the children in the DFS Tree.
    int child = 0;
    visited[u] = true;

    // Initialise the discovery time and the low value for u.
    disc[u] = ++time;
    low[u] = time;

    for (auto v : adj[u]) {
        // If v is not visited yet, make it a child of u in the DFS tree and repeat for it.
        if (!visited[v]) {
            child++;
            APUtil(adj, visited, disc, low, time, v, u, AP);

            // Check if the subtree rooted at v has a back edge to the ancestors of u.
            low[u] = min(low[u], low[v]);

            // If u is not the root and the low value of one of its children is more than the discovery time value of u.
            if (low[v] >= disc[u] && parent != -1)
                AP[u] = true;
        }

        // Update low value of u for the parent function calls.
        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }

    // Case 1, if u is the root of the DFS tree and has more than one child.
    if (parent == -1 && child > 1)
        AP[u] = true;
}

void AP(vector<vector<int>> &adj, int V)
{
    vector<int> disc(V);

    vector<int> low(V);

    vector<bool> visited(V, false);

    vector<bool> AP(V, false); 
    int time = 0;
    int par = -1;

    // Using the for loop so that the code works for disconnected the graph.
    for (int u = 0; u < V; ++u){
         if (!visited[u])
             APUtil(adj, visited, disc, low, time, u, par, AP);
    }

    // Printing the Articulation points.
    for (int i = 0; i < V; i++){
        if (AP[i] == true)
            cout << i << " ";
    }
}

int main()
{
    cout << "Articulation points: ";
    int V = 5;
    int E = 6;
    vector<vector<int>> adj(V);
    addEdge(adj, 1, 0);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    AP(adj, V);
    return 0;
}