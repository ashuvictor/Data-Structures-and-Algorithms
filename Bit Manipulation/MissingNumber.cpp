/*

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
https://leetcode.com/problems/missing-number/
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int all=0;
        int n=nums.size();
        for(int i=0;i<=n;i++)
            all=all^i;
        int present=0;
        for(int x:nums)
            present=present^x;
        return all^present;
    }
};