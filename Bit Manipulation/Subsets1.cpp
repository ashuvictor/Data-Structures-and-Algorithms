/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
https://leetcode.com/problems/subsets/
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        int possible=pow(2,n);
        for(int i=0;i<possible;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};