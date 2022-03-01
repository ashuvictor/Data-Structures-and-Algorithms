/*

Given a set of positive integers, check if it can be divided into two subsets with equal sum.

Input: S = [3, 1, 1, 2, 2, 1]
Output: true
Explanation: S can be partitioned into two partitions, each having a sum of 5.

S1 = [1, 1, 1, 2]
S2 = [2, 3]

Note that this solution is not unique. Here’s another solution.

S1 = [3, 1, 1]
S2 = [2, 2, 1]
https://techiedelight.com/practice/?problem=PartitionProblem
*/

class Solution
{
public:

	bool partition(vector<int> const &nums)
	{
		// Write your code here...
		int sum=0;int n=nums.size();
		for(int i=0;i<n;i++){
			sum+=nums[i];
		}
		if(sum%2==1)
		return false;
		else
		{
				sum=sum/2;
	int dp[n+1][sum+1];
	for(int i=1;i<=sum;i++)
	dp[0][i]=false;
	for(int i=0;i<=n;i++)
	dp[i][0]=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(nums[i-1]<=j)
			dp[i][j]=dp[i-1][j] or dp[i-1][j-nums[i-1]];
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][sum];
		}

		
		
		
	}
};