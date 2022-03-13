A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          int rows=obstacleGrid.size();
       int cols=obstacleGrid[0].size();
       int dp[rows][cols];
      bool flag=false;
        for(int i=0;i<rows;i++){
            if(flag or obstacleGrid[i][0]==1)
            {
                dp[i][0]=0;flag=true;
            }
            else
                dp[i][0]=1;
        }
        flag=false;
        for(int i=0;i<cols;i++){
            if(flag or obstacleGrid[0][i]==1)
            {
                flag=true;dp[0][i]=0;
            }
            else
                dp[0][i]=1;
        }
        for(int i=1;i<rows;i++){{
            for(int j=1;j<cols;j++){
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }}
       return dp[rows-1][cols-1];
    }
};


  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
       int rows=obstacleGrid.size();
       int cols=obstacleGrid[0].size();
       int dp[rows][cols];
       for(int i=0;i<rows;i++){
           for(int j=0;j<cols;j++){
               if(obstacleGrid[i][j]==1)
               dp[i][j]=0;
               else if(i==0  and j==0)
               dp[i][j]=1;
               else{
                   int up=0,left=0;
                   if(i>0)
                   up=dp[i-1][j];
                   if(j>0)
                   left=dp[i][j-1];
                   dp[i][j]=up+left;
               }
           }
       }
       return dp[rows-1][cols-1];
    }
};