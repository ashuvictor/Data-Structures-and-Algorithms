Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto x:nums1)
            mp[x]++;
        for(auto y:nums2){
            if(mp[y]>0)
            {
                ans.push_back(y);mp[y]--;
            }
        }
        return ans;
    }
};