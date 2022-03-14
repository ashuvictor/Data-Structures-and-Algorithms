
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
                ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};