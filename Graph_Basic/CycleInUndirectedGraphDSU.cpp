https://www.interviewbit.com/problems/cycle-in-undirected-graph/
Problem Description

Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast three nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
1 <= A, M <= 3105

1 <= B[i][0], B[i][1] <= A




int findParent(int ele,vector<int>&ds)
{
    if(ds[ele]==ele)
    return ele;
    return findParent(ds[ele],ds);
}
int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int>ds(A+1);
    vector<int>rank(A+1);
    for(int i=1;i<=A;i++){
        ds[i]=i;
        rank[i]=i;
    }
    for(auto x:B){
        int element1=x[0];
        int element2=x[1];
        int p1=findParent(element1,ds);
        int p2=findParent(element2,ds);
        if(p1==p2)
        return 1;
        else{
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
                  rank[p1]++;
            }
        }
    }
    return 0;
}