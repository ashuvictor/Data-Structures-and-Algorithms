/* FLLOYD WARSHALL
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
 The Graph is represented as adjancency matrix, and the matrix denotes the weight of the edegs (if it exists) else -1.
 The Floyd Warshall algorithm is a classic dynamic programming approach used to compute the shortest paths between all pairs of vertices in a weighted graph. It works even when some edge weights are negative, as long as there are no negative cycles.

Below is an overview of how it works:

How It Works
Initialization:
Create a 2D distance matrix (or array) D where D[i][j] is initialized with:

The weight of the edge from vertex i to vertex j if one exists,
Zero if i equals j (distance from a vertex to itself), or
Infinity if there is no direct edge between i and j.
Dynamic Programming Update:
For each vertex k (acting as an intermediate vertex), update every pair of vertices (i, j) by checking if a path through k offers a shorter route:
D[i][j]=min(D[i][j],D[i][k]+D[k][j])
This process is repeated for each vertex k.

Negative Cycle Check:
After the algorithm finishes, if any diagonal entry D[i][i] is negative, it indicates the presence of a negative cycle in the graph
  Do it in-place.
https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1/?page=1&difficulty[]=1&status[]=solved&category[]=Graph&sortBy=submissions
*/
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int k=0; k<n; k++) {
	        for(int i=0; i<n; i++) {
	            for(int j=0; j<n; j++) {
	                if(matrix[i][k]==-1 || matrix[k][j]==-1) continue;
	                if(matrix[i][j]==-1) matrix[i][j] = matrix[i][k] + matrix[k][j];
	                else matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	}
};
