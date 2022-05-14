

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.
https://leetcode.com/problems/unique-number-of-occurrences/
 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
    set<int>m;
        for(auto p:mp)
        {
           m.insert(p.second);
        }
       if(m.size()==mp.size())
           return true;
        return false;
    }
};