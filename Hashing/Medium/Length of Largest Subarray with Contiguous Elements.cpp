Length of longest subarray with increasing contiguous elements
Last Updated : 26 Apr, 2021
Given an array arr[] of length N, the task is to find the length of the longest subarray which consists of consecutive numbers in increasing order, from the array.

Examples:

Input: arr[] = {2, 3, 4, 6, 7, 8, 9, 10}
Output: 5
Explanation: Subarray {6, 7, 8, 9, 10} is the longest subarray satisfying the given conditions. Therefore, the required output is 5.

Input: arr[] = {4, 5, 1, 2, 3, 4, 9, 10, 11, 12}
Output: 4

https://www.youtube.com/watch?v=37MdIo-MaSU&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=7&t=12s

max-min=i-j


int contiguousElements(vector<int>&nums,int n){
    int ans=0;

    for(int i=0;i<n-1;i++){
        int mini=nums[i];
        int maxa=nums[i];
        set<int>duplicacy;
        duplicacy.add(nums[i]);
    for(int j=i+1;j<n;j++){
       if(duplicacy.find(nums[j])!=duplicacy.end())
       break;
       duplicacy.insert(nums[j]);
       mini=min(mini,nums[j]);
       maxa=max(maxa,nums[j]);
       if((maxa-mini)==(j-i))
       ans=j-i+1;
    }
    }
    return ans;
}