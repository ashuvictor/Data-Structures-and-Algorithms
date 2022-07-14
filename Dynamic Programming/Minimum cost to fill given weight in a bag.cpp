Minimum cost to fill given weight in a bag 
Medium Accuracy: 45.25% Submissions: 27066 Points: 4
Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges, the task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.

Example 1:

Input: N = 5, arr[] = {20, 10, 4, 50, 100}
W = 5
Output: 14
Explanation: choose two oranges to minimize 
cost. First orange of 2Kg and cost 10. 
Second orange of 3Kg and cost 4. 
Example 2:

Input: N = 5, arr[] = {-1, -1, 4, 3, -1}
W = 5
Output: -1
Explanation: It is not possible to buy 5 
kgs of oranges




class Solution{
	public:
   long long int dp[201][201];
   long long int helper(int cost[],int n,int w){
       if(w == 0) return 0;
       if(n == 0 || w < 0) return INT_MAX;
       if(dp[n][w] != -1) return dp[n][w];
       if(cost[n-1] != -1)
           return dp[n][w] = min(cost[n-1] + helper(cost,n,w-n), helper(cost,n-1,w));
       else return dp[n][w] = helper(cost,n-1,w);
   }
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        memset(dp,-1,sizeof(dp));
        return helper(cost,N,W);
	} 
};





class Solution{

	public:
	
	int minimumCost(int cost[], int N, int W) 
	{ 
	    vector<vector<int>> dp(N+1, vector<int>(W+1));
	    
	    for(int i=0; i<=W; i++){
	        dp[0][i] = 1000000;
	    }
	    for(int i=0; i<=N; i++){
	        dp[i][0] = 0;
	    }
	    
	    for(int i=1; i<=N; i++){
	        for(int j=1; j<=W; j++){
	            if(cost[i-1] != -1){
	                if(j-i >= 0){
	                    dp[i][j] = min(dp[i-1][j], cost[i-1] + dp[i][j-i]);
	                }
	                else{
	                    dp[i][j] = dp[i-1][j];
	                }
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    return (dp[N][W] >= 1000000) ? -1 : dp[N][W];
	} 
};




int minimumCost(int cost[], int N, int W) 
{ 
       // Your code goes here
       vector<int>dp(W+5,1e9);
        dp[0]=0;
       for(int i=0;i<=W;i++)
       {
           if(dp[i]!=1e9)
           {
           for(int j=0;j<N;j++)
           {
               if(cost[j]!=-1&&i+j+1<=W)
               dp[i+j+1]=min(dp[i+j+1],dp[i]+cost[j]);
           }
           }
       }
       if(dp[W]==1e9) return -1;
       return dp[W];
} 