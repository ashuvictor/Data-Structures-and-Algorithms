
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 https://leetcode.com/problems/minimum-falling-path-sum/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int dp[n][n];
        for(int i=0;i<n;i++)
            dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
             if(j==0)
                 dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==n-1)
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                else
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]));
                
                   
            }
        }
        int ans=dp[n-1][0];
        for(int i=1;i<n;i++)
            ans=min(ans,dp[n-1][i]);
        return ans;
    }
};