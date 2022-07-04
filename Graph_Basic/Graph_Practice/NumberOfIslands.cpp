Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
       if(i<0||i>=n||j<0||j>=m||grid[i][j]=='2'||grid[i][j]=='0')
        return;
        grid[i][j]='2';
         dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
           int n = grid.size(), m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1') {
                    dfs(grid, i, j,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};