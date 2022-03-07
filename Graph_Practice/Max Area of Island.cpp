ou are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
https://leetcode.com/problems/max-area-of-island/


class Solution {
public:
     int cnt=0;
void dfs(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<bool>>&visited){
        if(i<0 or i>=m or j<0 or j>=n or visited[i][j]==true or grid[i][j]==0)
            return;
        visited[i][j]=true;
    cnt++;
         dfs(grid,i+1,j,m,n,visited);
         dfs(grid,i,j-1,m,n,visited);
         dfs(grid,i,j+1,m,n,visited);
         dfs(grid,i-1,j,m,n,visited);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int len=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and visited[i][j]==false)
                { 
                    dfs(grid,i,j,m,n,visited);
                 len=max(len,cnt);
                 cnt=0;
                }
            }
        }
        return len;
    }
};