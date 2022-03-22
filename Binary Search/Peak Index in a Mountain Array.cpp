


https://leetcode.com/problems/peak-index-in-a-mountain-array/

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

 

Example 1:

Input: arr = [0,1,0]
Output: 1
Example 2:

Input: arr = [0,2,1,0]
Output: 1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid==0)
                return 1;
            if(arr[mid]>arr[mid-1] and arr[mid]>arr[mid+1])
                return mid;
           if(arr[mid]<arr[mid-1])
                high=mid-1;
            else if(arr[mid]<arr[mid+1])
                low=mid+1;
        }
        return -1;
    }
};