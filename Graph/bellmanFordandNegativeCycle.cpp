/* BELLMAN FORD ALGORITHM
https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1/?page=1&difficulty[]=1&status[]=solved&category[]=Graph&sortBy=submissions
NEGATIVE WEIGHT CYCLE
https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1/?page=2&difficulty[]=1&category[]=Graph&sortBy=submissions
*/
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
       vector<int>dist(V,1e8);
       dist[S]=0;
       for(int i=0;i<V-1;i++){
           for(auto x:adj){
               int u=x[0],v=x[1],wt=x[2];
               if(dist[u]+wt<dist[v])
               dist[v]=dist[u]+wt;
           }
       }
       return dist;
    }
};

NEGATIVE WEIGHT CYCLE
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int>dist(n,INT_MAX);
	    dist[0]=0;
	    for(int i=0;i<n;i++){
	   for(auto x:edges){
	       int u=x[0],v=x[1],wt=x[2];
	       if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
	       dist[v]=dist[u]+wt;
	   }
	    }
	    for(auto x:edges){
	         int u=x[0],v=x[1],wt=x[2];
	       if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
	       {dist[v]=dist[u]+wt;
	       return true;
	    }
	}
	return false;}