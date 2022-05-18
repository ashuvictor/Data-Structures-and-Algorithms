
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    { int indegree[n]={0};
int outdegree[n]={0};
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(M[i][j]==1){
            indegree[j]++;
            outdegree[i]++;
        }
    }}
    for(int i=0;i<n;i++){
        if(indegree[i]==n-1 && outdegree[i]==0)
       return i;
    }
    return -1;}
        // code here 
    
};




class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++)
        st.push(i);
        while(st.size()>=2){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            if(M[first][second]==0)
            st.push(first);
            else
            st.push(second);
        }
        int celebrity=st.top();
        st.pop();
        for(int i=0;i<n;i++){
            if(i!=celebrity){
                if(M[i][celebrity]==0 or M[celebrity][i]==1)
                return -1;
            }
        }
        return celebrity;
    }
};