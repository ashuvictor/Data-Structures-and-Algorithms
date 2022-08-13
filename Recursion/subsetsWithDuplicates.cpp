/*https://leetcode.com/problems/subsets-ii/
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            if(i>ind and nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,nums,temp,ans);
        return ans;
    }
};