/* FLLOYD WARSHALL
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
 The Graph is represented as adjancency matrix, and the matrix denotes the weight of the edegs (if it exists) else -1.
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
