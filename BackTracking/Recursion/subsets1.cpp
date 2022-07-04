/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
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
class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,vector<int>&nums,vector<int>temp){
        if(i==nums.size())
        {
            ans.push_back(temp);return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp);
        temp.pop_back();
        solve(i+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        solve(0,nums,temp);
        return ans;
    }
};