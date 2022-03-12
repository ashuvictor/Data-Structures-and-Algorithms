Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findParent(int element,vector<int>ds)
	{
	    if(element==ds[element])
	    return element;
	    return ds[element]=findParent(ds[element],ds);
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>ds;
        for(int i=0;i<V;i++)
        ds[i]=i;
        vector<int>rank(V,1);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<V;i++){
            vector<vector<int>>v=adj[i];
            for(auto x:v)
            {
                pq.push({x[1],{i,x[0]}});
            }
        }
        int count=0;
        int sum=0;
        while(count<V-1){
            int dist=pq.top().first;
            int elem1=pq.top().second.first;
            int elem2=pq.top().second.second;
            pq.pop();
            int p1=findParent(elem1,ds);
            int p2=findParent(elem2,ds);
            if(p1!=p2)
            {
                if(rank[p1]<rank[p2])
                {
                    ds[p1]=p2;
                }
                else if(rank[p2]<rank[p1])
                {
                    ds[p2]=p1;
                }
                else{
                    ds[p1]=p2;
                    rank[p2]++;
                }
            sum+=dist;
                count++;
            }
        }
        return sum;
    }
};