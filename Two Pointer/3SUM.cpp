
https://leetcode.com/problems/3sum/
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []

BRUTE FORCE
for(i=0 to n-1)
for(j=0 to n-1)
for(k=0 to n-1)
use a set for unique triplets


optimal
hashing
elements with their occurence 
now two loops 
for(i =0 to n-1)  //use the element and remove from the hashtable
for(j=i+1 to n-1)

//now insert into  the set for unique triplets


BEST





class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        if(n==0)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]>0)
                break;
            if(i>0 and nums[i]==nums[i-1])
                continue;
            int j=i+1,k=n-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];
                if(s==0)
                   { ans.push_back({nums[i],nums[j],nums[k]});
                   while(j<k and nums[j]==nums[j+1])
                    j++;
                   while(k>j and nums[k]==nums[k-1])
                    k--;
                   j++;
                   k--;}
                else if(s>0)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int sz=nums.size();
        for(int i=0;i<sz-2;i++){
            if(i==0 or(i>0 and nums[i]!=nums[i-1]))
            {
                int low=i+1,high=sz-1;
                int sum=0-nums[i];
                while(low<high)
                {
                    if(nums[low]+nums[high]==sum)
                    {
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        ans.push_back(temp);
                        while(low<high and nums[low]==nums[low+1]) low++;
                        while(low <high and nums[high]==nums[high-1]) high--;
                        low++;high--;
                    }
                    else if(nums[low]+nums[high]<sum)
                        low++;
                    else
                        high--;
                }
            }
        }
        return ans;
    }
};