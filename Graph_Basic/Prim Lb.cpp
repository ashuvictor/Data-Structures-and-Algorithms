



#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
        
    }
    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);
    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<n;i++){
        int mini=INT_MAX;
        int u;
        //finding min node
        for(int v=1;v<=n;v++){
            if(mst[v]==false and key[v]<mini)
            {
                u=v;
                mini=key[v];
            }
        }
        //mark min node as true
        mst[u]=true;
        //check adjacent nodes
        for(auto it:adj[u])
        {
            int v=it.first;
            int w=it.second;
            if(mst[v]==false and w<key[v])
            {
                parent[v]=u;
                key[v]=w;
            }
        }
    }
       vector<pair<pair<int, int>, int>>result;
        for(int i=2;i<=n;i++){
            result.push_back({{parent[i],i},key[i]});
        }
        return result;
    
}



#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}