/*

Given an array containing positive and negative elements, find a subarray with alternating positive and negative elements, and in which the subarray is as long as possible.

Input : [1, -2, 6, 4, -3, 2, -4, -3]
Output: [4, -3, 2, -4]

Note that the longest alternating subarray might not be unique. In case the multiple alternating subarrays of maximum length exists, the solution can return any one of them.

Input : [1, -2, 6, 2, 4, -3, 2, 4, -3]
Output: [1, -2, 6] or [4, -3, 2]

*/

class Solution
{
public:
	vector<int> findLongestAlternatingSubarray(vector<int> const &nums)
	{
		// Write your code here...
		vector<int>ans;
		int n=nums.size();
		if(n==1)
		return nums;
		int max_len=1;
		int curr_len=1;
		int ending=-1;
		for(int i=1;i<n;i++){
			if(nums[i]*nums[i-1]<0)
			{
				curr_len++;
				if(curr_len>max_len)
				{
					max_len=curr_len;
					ending=i;
				}
			}
			else
			curr_len=1;
		}
		if(ending!=-1)
		{
			for(int i=ending-max_len+1;i<=ending;i++)
			ans.push_back(nums[i]);
			
		}
		
		return ans;
		
	}
};