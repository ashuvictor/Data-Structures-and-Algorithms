int dp[10001];

    int recursion(int *arr,int i,int n)

    {

        if(i>=n)    return 0;

        if(dp[i]!=-1) return dp[i];

        int ans1=arr[i]+recursion(arr,i+2,n);

        int ans2=recursion(arr,i+1,n);

        return dp[i]=max(ans1,ans2);

    }

    int FindMaxSum(int arr[], int n)

    {

        for(int i=0;i<=n;i++)

            dp[i]=-1;

        return recursion(arr,0,n);

    }




