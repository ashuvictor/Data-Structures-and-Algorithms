/*
Given an array, 
rotate the array to the right by k steps, where k is non-negative.
https://leetcode.com/problems/rotate-array/*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
      
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[(i+k)%n]=nums[i];
        }
        for(int i=0;i<n;i++)
            nums[i]=ans[i];
    }
};

class Solution {
public:
    void rotateLeft(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k is greater than the size of the vector
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[(i - k + n) % n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};



class Solution {
public:
   void reverse(vector<int>&nums,int low,int high){
       while(low<=high){
           swap(nums[low],nums[high]);
           low++;high--;
       }
   }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
    }
};
