/*Maximum sum increasing subsequence
https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1/?page=1&difficulty[]=1&status[]=solved&category[]=Dynamic%20Programming&sortBy=submissions
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
*/
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    if(n==1)
	    return arr[0];
	    int dp[n+1];
	    dp[0]=arr[0];
	    int res=arr[0];
	    for(int i=1;i<n;i++){
	        dp[i]=arr[i];
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i])
	            dp[i]=max(dp[i],dp[j]+arr[i]);
	        }
	        res=max(res,dp[i]);
	    }
	    return res;
	}  
};