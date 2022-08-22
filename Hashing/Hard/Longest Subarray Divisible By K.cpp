
https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1/
Given an array containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Example 1:

Input:
A[] = {2, 7, 6, 1, 4, 5}
K = 3
Output: 4
Explanation:The subarray is {7, 6, 1, 4}
with sum 18, which is divisible by 3.
Example 2:

Input:
A[] = {-2, 2, -5, 12, -11, -1, 7}
K = 3
Output: 5
Explanation:
The subarray is {2,-5,12,-11,-1} with
sum -3, which is divisible by 3.


//we will be checking when the remainder of subarray is same

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    unordered_map<int,int>m;
	    m[0]=-1;int ans=0;
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        int rem=sum%k;
	        if(rem<0)
	        rem+=k;
	        if(m.find(rem)==m.end())
	        m[rem]=i;
	        else{
	            ans=max(ans,i-m[rem]);
	        }
	    }
	    return ans;
	}
};