



#include<bits/stdc++.h>
using namespace std;
class Graph{
public:
map<int,list<int>>adj;
void addEdge(int u,int v,bool direction){
	adj[u].push_back(v);
	if(direction)
	adj[v].push_back(u);
}
void print(){
	for(auto i:adj)
	{
		cout<<i.first<<"->";
		for(auto x:i.second){
			cout<<x<<",";
		}
		cout<<endl;
	}
}
};
int main() {
	// your code goes here
    int n;
	cout<<"Enter the number of nodes "<<endl;
	cin>>n;
	int m;
	cout<<"Enter the Number of Edges"<<endl;   
	cin>>m;
	Graph g;
for(int i=0;i<m;i++){
	int u,v;
	cin>>u>>v;
  g.addEdge(u,v,true);
}
g.print();
	return 0;
}

