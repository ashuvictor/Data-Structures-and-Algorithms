/*Equal sum partition
https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/
   int solve(int arr[],int sum,int n){
      
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)
                dp[i][j]=0;
                else if(j==0)
                dp[i][j]=1;
                else if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    int equalPartition(int N, int arr[])
    {
       int sum=0;
       for(int i=0;i<N;i++){
           sum+=arr[i];
       }
       if(sum%2==0)
       return solve(arr,sum/2,N);
       else 
       return 0;
    }
       
