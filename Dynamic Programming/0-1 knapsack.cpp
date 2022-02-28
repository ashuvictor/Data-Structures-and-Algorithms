/*0-1 knapsack 
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/
1	     int knapSack(int W, int wt[], int val[], int n) 
2	    { 
3	      int dp[n+1][W+1];
4	      for(int i=0;i<=n;i++){
5	          for(int j=0;j<=W;j++){
6	              if(i==0 or j==0)
7	              dp[i][j]=0;
8	              else if(wt[i-1]<=j)
9	{
10	    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
11	}          
12	              else{
13	                  dp[i][j]=dp[i-1][j];
14	              }
15	          }
16	      }
17	      return dp[n][W];
18	    }
