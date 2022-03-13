You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
https://leetcode.com/problems/jump-game/
 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int reachable=0;
        for(int i=0;i<nums.size();i++){
            if(reachable<i)
                return false;
            reachable=max(reachable,i+nums[i]);
        }
        return true;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr_max=0;
        int sz=nums.size();
        for(int i=0;i<sz;i++){
            if((i+nums[i])>=curr_max)
                curr_max=i+nums[i];
            if(i==curr_max and curr_max<sz-1)
                return false;
            if(curr_max>=sz-1)
                return true;
        }
        return false;
    }
};