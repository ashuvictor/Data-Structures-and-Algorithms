/*Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first increasing, then decreasing.
https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1/
*/
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	   int n=nums.size();
	   int forward[n],backward[n];
	  forward[0]=1;
	  for(int i=1;i<n;i++){
	      forward[i]=1;
	      for(int j=0;j<i;j++){
	          if(nums[j]<nums[i])
	          forward[i]=max(forward[i],forward[j]+1);
	      }
	  }
	  backward[n-1]=1;
	  for(int i=n-2;i>=0;i--){
	      backward[i]=1;
	      for(int j=i+1;j<n;j++)
	      {
	           if(nums[j]>=nums[i])
	           continue;
	           backward[i]=max(backward[i],backward[j]+1);
	      }
	  }
	   int ans=INT_MIN;
	   for(int i=0;i<n;i++)
	   ans=max(ans,forward[i]+backward[i]-1);
	   return ans;
	}
};