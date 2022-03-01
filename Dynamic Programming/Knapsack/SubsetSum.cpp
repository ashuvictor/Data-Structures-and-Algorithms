/*

Given a set of positive integers and an integer `k`, check if there is any non-empty subset that sums to `k`.

Input: nums = [7, 3, 2, 5, 8], k = 14
Output: true
Explanation: Subset [7, 2, 5] sums to 14
https://techiedelight.com/practice/?problem=SubsetSumProblem
*/

class Solution
{
public:
	bool subsetSum(vector<int> const &nums, int k)
	{
		// Write your code here...
		int n=nums.size();
		int dp[n+1][k+1];
		for(int i=1;i<=k;i++)
		dp[0][i]=false;
		for(int i=0;i<=n;i++)
		dp[i][0]=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(nums[i-1]<=j)
				dp[i][j]=dp[i-1][j] or dp[i-1][j-nums[i-1]];
				else
				dp[i][j]=dp[i-1][j];
			}
		}
		return dp[n][k];
	}
};
