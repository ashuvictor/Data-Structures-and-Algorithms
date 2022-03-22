https://leetcode.com/problems/find-peak-element/
https://www.interviewbit.com/problems/find-a-peak-element/

A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

int Solution::solve(vector<int> &A) {
    if(A.size()==1)
    return 0;
    for(int i=0;i<A.size();i++){
        if(i==0 and A[0]>A[1])return A[0];
        else if(i==A.size()-1 and A[i]>A[i-1]) return A[i];
        else if(A[i]>=A[i-1] and A[i]>=A[i+1]) return A[i];
    }
    return -1;
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    
        if(nums.size()==1)
            return 0;
            int low=0,high=nums.size()-1;
        while(low<high){
          int mid=(low+high)/2;
            if((mid==0 or nums[mid]>nums[mid-1]) and (mid==nums.size()-1 or nums[mid]>nums[mid+1]))
                return mid;
          if(nums[mid]>nums[mid+1])
              high=mid;
            else low=mid+1;
        }
        return high;
    }
};