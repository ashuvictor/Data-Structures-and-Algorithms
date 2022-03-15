https://leetcode.com/problems/number-of-good-pairs/
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

Brute Force Solution

class Solution {
public:
	 int numIdenticalPairs(vector<int>& nums) {
			 int count = 0;
			 int size = nums.size();
			 for(int i = 0; i<size-1; i++){
				 for(int j = i+1; j<size; j++){
					if(nums[i] == nums[j]){
						 count++;
					}
				 }
			 }
			 return count;
		}
};
Hashmap Solution

class Solution {
public:
        int numIdenticalPairs(vector<int>& nums) {
            unordered_map<int, int> map;
            int size = nums.size();
            
            for(int i=0; i<size; i++){
                map[nums[i]]++;
            }
            int res = 0;
            for(auto &it: map){
                int n =  it.second;
                if(n > 0){
                    res =res + n * (n-1)/2;
                }
            }
            return res;
    }
};