/*MCM
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/#
*/
class Solution{
public:

int helper(int arr[],int i,int j,vector<vector<int>>&dp){
    if(i>=j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int res=INT_MAX;
    int temp;
    for(int k=i;k<j;k++){
        temp=helper(arr,i,k,dp)+helper(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
        res=min(res,temp);
    }
    return dp[i][j]=res;
}
    int matrixMultiplication(int N, int arr[])
    {  vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
      return helper(arr,1,N-1,dp);
        // code here
    }

    gap method
    class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
       int dp[N-1][N-1];
       for(int gap=0;gap<N-1;gap++){
           for(int i=0,j=gap;j<N-1;i++,j++){
               if(gap==0)
               dp[i][j]=0;
               else if(gap==1)
               dp[i][j]=arr[i]*arr[j]*arr[j+1];
               else{
                  int mincost=INT_MAX;
                  for(int k=i;k<j;k++){
                      int lc=dp[i][k];
                      int rc=dp[k+1][j];
                      int mc=arr[i]*arr[k+1]*arr[j+1];
                      int tc=lc+rc+mc;
                      mincost=min(tc,mincost);
                  }
                  dp[i][j]=mincost;
               }
           }
       }
       
       return dp[0][N-2];
    }
};