Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
https://leetcode.com/problems/01-matrix/
//the question is same as that of getting the distance from the node to all node in a undirected graph
class Solution {
public:
    bool checkValid(int i,int j,int m,int n){
        if(i<0  or i>=m or j<0 or j>=n)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       queue<pair<int,int>>q;
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),-1));
           for(int i=0;i<mat.size();i++){
               for(int j=0;j<mat[i].size();j++){
                   if(mat[i][j]==0)
                   {
                       q.push({i,j});ans[i][j]=0;
                   }
               }
           }
        int m=mat.size();
        int n=mat[0].size();
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            if(checkValid(i+1,j,m,n) and ans[i+1][j]==-1)  //chack for validity and not visited
            { q.push({i+1,j});
             ans[i+1][j]=ans[i][j]+1;
                
            }
             if(checkValid(i,j-1,m,n) and ans[i][j-1]==-1)  //chack for validity and not visited
            {  q.push({i,j-1});
             ans[i][j-1]=ans[i][j]+1;
                
            }
             if(checkValid(i,j+1,m,n) and ans[i][j+1]==-1)  //chack for validity and not visited
            {
                q.push({i,j+1});
                 ans[i][j+1]=ans[i][j]+1;
            }
             if(checkValid(i-1,j,m,n) and ans[i-1][j]==-1)  //chack for validity and not visited
            {
                q.push({i-1,j});
                 ans[i-1][j]=ans[i][j]+1;
            }
            q.pop();}
        return ans;
    }
};