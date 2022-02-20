/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
https://leetcode.com/problems/two-sum/*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int first=nums[i];
            if(mpp.find(target-first)!=mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[target-first]);
                return ans;
            }
            else{
                mpp[first]=i;
            }
        }
        return ans;
    }
};