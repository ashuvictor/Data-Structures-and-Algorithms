
https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

 

Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation: 
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1). 
For nums[3]=2 there exist one smaller number than it (1). 
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       int n=nums.size();
        vector<int>ans(n,0);
        unordered_map<int,int>mp;
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(copy[i])!=mp.end())
                continue;
            else
                mp[copy[i]]=i;
        }
        for(int i=0;i<n;i++)
            ans[i]=mp[nums[i]];
        return ans;
    }
};


//First Method : O(N) space and O(N^2) worst case time complexity
vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        vector<int> res;
        for(auto &num:nums)
            mp[num]++;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            for(auto &it : mp)
                if(it.first != nums[i] && it.first <= nums[i])
                    count += it.second;
            res.push_back(count);
            
        }
        return res;
    }
//Second Method : O(N) time and O(N) space, 0 ms
 vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> res;
        vector<int> cnt(101, 0);
        
        for(int i = 0; i < nums.size(); i++)
            cnt[nums[i]]++;
        
        for(int i = 1; i < cnt.size(); i++)
            cnt[i] += cnt[i - 1];
        
        for(int i = 0; i < nums.size(); i++)
        {
           if(nums[i] == 0)
               res.push_back(0);
           else 
               res.push_back(cnt[nums[i] - 1]);
            
        }
        return res;
    }