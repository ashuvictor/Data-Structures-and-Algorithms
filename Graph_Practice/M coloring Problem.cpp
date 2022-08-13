https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.


bool isSafeToAssign(int i,int j,bool graph[101][101],int V,vector<int>&color)
{
    for(int k=0;k<V;k++){
        if(graph[i][k]==1 and color[k]==j)return false;
    }
    return true;
}
bool solve(bool graph[101][101], int m, int V,int i,vector<int>&color){
    if(i==V)
    return true;
    for(int j=0;j<m;j++){
        if(isSafeToAssign(i,j,graph,V,color))
        {
            color[i]=j;
            if(solve(graph,m,V,i+1,color))  return true;
            color[i]=-1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    
    vector<int>color(V,-1);
    
    return solve(graph,m,V,0,color);
    
}