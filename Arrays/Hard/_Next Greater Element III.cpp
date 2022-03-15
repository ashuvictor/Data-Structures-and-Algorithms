https://leetcode.com/problems/next-greater-element-iii/
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
class Solution {
public:
    int nextGreaterElement(int n) {
          int temp=n;
        vector<int> nums;
        while (temp){                               
            nums.push_back(temp%10);
            temp=temp/10;
        }
        reverse(nums.begin(),nums.end());
        temp=nums.size();
        int k,m;
        for (k=temp-2;k>=0;k--){
            if (nums[k]<nums[k+1]) break;
        }
        if (k<0) return -1;
        else{
            for (m=temp-1;m>k;m--){
                if (nums[m]>nums[k]) break;
            }
            swap(nums[m],nums[k]);
            reverse(nums.begin()+k+1,nums.end());
        }
        long long int res=0;
        for (int i=0;i<temp;i++){
            res=res*10+nums[i];
        }
        if (res>INT_MAX) return -1;
        return res;
    }
};