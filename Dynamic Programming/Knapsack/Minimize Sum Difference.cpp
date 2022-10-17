class Solution 
{
public:
    int minimumDifference(vector<int>& nums) 
    {
         int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }
        bool dp[n+1][sum+1];
        for(int i=0; i<=n; i++)
        {
            dp[i][0] = true;
        }
        for(int i=1; i<=sum; i++)
        {
            dp[0][i] = false;
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
                }
            }
        int diff = INT_MAX;
       for (int j = 0; j<=sum/2; j++) 
       {
           int first=j;
           int second=sum-j;
            if (dp[n][j] == true && diff>abs(first-second)) 
            {
                diff=abs(first-second);
            }
        }

        return diff;
    }
};