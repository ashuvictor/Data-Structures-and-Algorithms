A number n can be broken into three parts n/2, n/3 and n/4 (consider only integer part). Each number obtained in this process can be divided further recursively. Find the maximum sum that can be obtained by summing up the divided parts together.
Note: The maximum sum may be obtained without dividing n also.

 

Example 1:

Input:
n = 12
Output: 13
Explanation: Break n = 12 in three parts
{12/2, 12/3, 12/4} = {6, 4, 3}, now current
sum is = (6 + 4 + 3) = 13. Further breaking 6,
4 and 3 into parts will produce sum less than
or equal to 6, 4 and 3 respectively.

https://practice.geeksforgeeks.org/problems/maximum-sum-problem2211/1/?category

class Solution
{
    public:
        int maxSum(int n)
        {
          int dp[n+1]={0};int c=0;
          dp[0]=0,dp[1]=1,dp[2]=1;
          for(int i=2;i<=n;i++){
              dp[i]=max(i/2,dp[i/2])+max(i/3,dp[i/3])+max(i/4,dp[i/4]);
              c=max(c,dp[i]);
          }
          return c;
        }
};