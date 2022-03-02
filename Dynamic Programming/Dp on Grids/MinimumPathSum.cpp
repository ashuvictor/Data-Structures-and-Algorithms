/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
https://leetcode.com/problems/minimum-path-sum/
*/

Recursive Solution

int getMinPath(vector <vector <int>> &grid, int i, int j) {
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        int m = INT_MAX;
        if (j > 0) {
            m = grid[i][j] + getMinPath(grid, i, j - 1);
        }
        if (i > 0) {
            int s = grid[i][j] + getMinPath(grid, i - 1, j);
            m = min(m, s);
        }
        return m;
    }
    


Top Down DP - Memoization

int getMinPath(vector <vector <int>> &grid, int i, int j, vector <vector<int>> &dp) {
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int m = INT_MAX;
        if (j > 0) {
            m = grid[i][j] + getMinPath(grid, i, j - 1, dp);
        }
        if (i > 0) {
            int s = grid[i][j] + getMinPath(grid, i - 1, j, dp);
            m = min(m, s);
        }
        
        dp[i][j] = m;
        return dp[i][j];
    }


Bottom Up DP - Table Filling


  class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,INT_MAX));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 and j==0)
                    dp[i][j]=grid[i][j];
                else{
                    int right=INT_MAX,down=INT_MAX;
                    if(i>0)
                        down=grid[i][j]+dp[i-1][j];
                    if(j>0)
                        right=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(right,down);
                }
            }
        }
        return dp[r-1][c-1];
    }
};