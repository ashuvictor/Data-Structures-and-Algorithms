Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/#
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int len=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
                
            }
            else{
                len=max(len,i-mp[sum]);
            }
        }
        return len;
    }
};
