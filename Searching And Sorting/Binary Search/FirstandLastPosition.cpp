 /*FIRST AND LAST POSITION OF A ELEMENT IN A SORTED ARRAY USING BINARY SEARCH
 https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */
 class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==target)
            {ans[0]=mid;
            high=mid-1;}
            else if(nums[mid]>target){
                high=mid-1;

            }
            else
            low=mid+1;
        }
        if(ans[0]!=-1){
            low=0,high=nums.size()-1;
            while(low<=high){
                int mid=(low+high)>>1;
                if(nums[mid]==target){
                    ans[1]=mid;
                    low=mid+1;
                }
                else if(nums[mid]>target){
                high=mid-1;

            }
            else
            low=mid+1;

            }
        }
    return ans;}
};