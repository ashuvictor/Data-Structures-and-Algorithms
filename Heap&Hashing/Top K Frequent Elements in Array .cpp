Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. If two numbers have the same frequency then the larger number should be given preference. 

Note: Print the elements according to the frequency count (from highest to lowest) and if the frequency is equal then larger number will be given preference.

Example 1:

Input:
N = 6
nums = {1,1,1,2,2,3}
k = 2
Output: {1, 2}
https://practice.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1/#
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
        priority_queue<pair<int,int>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
            
        }
      vector<int>ans;
      for(int i=0;i<k;i++)
      {
          ans.push_back(pq.top().second);pq.pop();
      }
      return ans;
    }
};