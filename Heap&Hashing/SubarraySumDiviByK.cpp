/*  
Subarray sum divisible by k 
logic is to find the subarrays which have same remainder
https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1/#
*/
class Solution{ 
	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    // Your code goes here
	    long long int ans=0;
	    unordered_map<long long int,int>mp;
	    long long int currsum=0;
	    mp[0]++;
	    for(int i=0;i<N;i++)
	    {
	        currsum+=arr[i];
	        int rem=currsum%K;
	        if(rem<0)
	        rem=rem+K;
	        if(mp.find(rem)!=mp.end())
	        ans+=mp[rem];
	        mp[rem]++;
	    }
	    return ans;
	}



};