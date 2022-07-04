You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
//mark all the ones from the boundary as 0
class Solution {
public:
    int cnt;
    void dfs(vector<vector<int>>&grid,int i,int j){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==0)
            return;
       
        grid[i][j]=0;
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(i==0 or i==m-1 or j==0 or j==n-1)
               {
                   if(grid[i][j]==1)
                       dfs(grid,i,j);
               }
           }
       }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};