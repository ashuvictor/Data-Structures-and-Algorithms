/*Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.
https://leetcode.com/problems/squares-of-a-sorted-array/
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int n=nums.size();
        vector<int>ans(n);
        int i=0,j=n-1;
        int index=n-1;
        while(i<=j){
            int val1=nums[i]*nums[i];
            int val2=nums[j]*nums[j];
            if(val1>val2){
                ans[index--]=val1;
                i++;
            }
            else{
                ans[index--]=val2;
                j--;
            }
        }
        return ans;
    }
};