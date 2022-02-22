COIN CHANGE COMBINATION

Given a value N, find the number of ways to make change for N cents,
 if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.
     long long int count(int S[], int m, int n) {

     vector<long long int>dp(n+1,0);
     dp[0]=1;
     for(int i=0;i<m;i++){
         for(int j=S[i];j<=n;j++){
             dp[j]+=dp[j-S[i]];
         }
     }
     return dp[n];
     
    }
Permutation
    vector<long long int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++){
            if(S[j]<=i){
                dp[i]+=dp[i-S[j]];
            }
        }
    }
    return dp[n];

min coins
    int minCoins(int coins[], int M, int V) 
    { 
        int dp[V+1]={0};
      
        for(int i=1;i<=V;i++){
            dp[i]=INT_MAX-1;
            for(int j=0;j<M;j++){
                if(coins[j]<=i)
            {
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
                
            }
        }
        if(dp[V]==INT_MAX-1)
        return -1;
        else
        return dp[V];
    } 
