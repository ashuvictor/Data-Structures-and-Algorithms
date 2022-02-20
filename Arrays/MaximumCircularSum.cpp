/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and 
the previous element of nums[i] is nums[(i - 1 + n) % n].

https://leetcode.com/problems/maximum-sum-circular-subarray/ */
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int maxs=INT_MIN,mins=INT_MAX,curr1=0,curr2=0,total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            curr1+=nums[i];
            maxs=max(curr1,maxs);
        curr1=max(curr1,0);
            curr2+=nums[i];
            mins=min(curr2,mins);
            curr2=min(curr2,0);
        }
        return maxs<0?maxs:max(maxs,total-mins);
        
    }
};