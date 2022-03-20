

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini=INT_MAX;
        int maxa=INT_MIN;
        int n=nums.size();
        if(n==1)
            return 0;
        for(int i=0;i<n;i++){
            if(i==0)
            {
                if(nums[i]>nums[i+1]) 
                {
                    mini=min(mini,nums[i]);
                maxa=max(maxa,nums[i]);
                }
            }
            else if(i==n-1){
                if(nums[i]<nums[i-1])
                {
                     mini=min(mini,nums[i]);
                maxa=max(maxa,nums[i]);
                }
            }
           else{
           if((nums[i]>nums[i+1]) or (nums[i]<nums[i-1]))
            {
                mini=min(mini,nums[i]);
                maxa=max(maxa,nums[i]);
            }} 
        }
        if(mini==INT_MAX or maxa==INT_MIN)
            return 0;
        //find position of max and min
        int i,j;
        for(i=0;i<n and nums[i]<=mini;i++);
        for(j=n-1;j>=0 and nums[j]>=maxa;j--);
            
        
        return j-i+1;
        
    }
};
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.

Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.

If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]

https://www.interviewbit.com/problems/maximum-unsorted-subarray/

vector<int> Solution::subUnsort(vector<int> &A){
 vector<int> ans;
 int n = A.size();
 int i = 0, j = n-1;
 while(i< n - 1 and A[i] <= A[i + 1]){
  i++;
 }
 while(j > 0 and A[j] >= A[j - 1]){
  j--;
 }
 if(i == n - 1){ // if array is already sorted, output -1
  ans.push_back(-1);
  return ans;
 }
 int mn = A[i + 1], mx = A[i + 1];
 for(int k = i; k <= j; k++){
  mx = max(mx, A[k]);
  mn = min(mn, A[k]);
 }
 int l = 0, r = n - 1;
 while(A[l] <= mn and l <= i){
     l++;
 }
 while(A[r] >= mx and r >= j){
  r--;
 }
 ans.push_back(l);
 ans.push_back(r);
 return ans;
}