/* FIRST MISSING POSITIVE
Given an unsorted integer array nums,
 return the smallest missing positive integer.
https://leetcode.com/problems/first-missing-positive/
You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 and nums[i]<=n and nums[nums[i]-1]!=nums[i])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                return i+1;
        return n+1;
    }
};