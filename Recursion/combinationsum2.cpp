/*
https://leetcode.com/problems/combination-sum-ii/
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/
class Solution {
public:
    void solve(int ind,int target,vector<int>&candidates,vector<int>&temp,vector<vector<int>>&ans){
        if(target<0)
            return;
        else if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        else
        {
            for(int i=ind;i<candidates.size();i++){
                if(i>ind and candidates[i]==candidates[i-1])
                    continue;
                temp.push_back(candidates[i]);
                solve(i+1,target-candidates[i],candidates,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,temp,ans);
        return ans;
    }
};