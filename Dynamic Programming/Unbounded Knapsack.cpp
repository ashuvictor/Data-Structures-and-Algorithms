class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[W+1]={0};
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]<=j)
                dp[j]=max(dp[j],val[i-1]+dp[j-wt[i-1]]);
            }
        }
        return dp[W];
        
    }
};