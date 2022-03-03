You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

/*
divide the array into two parts such that left all elements occur twice
and from right first element is single every twice
right 
1st instance at odd 2nd instance at even
left 
1st at even and second at odd

*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==nums[mid^1])
                low=mid+1;
            else
                high=mid-1;
        }
        return nums[low];
    }
};
