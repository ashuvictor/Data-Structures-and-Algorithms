/*
Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/
*/
brute force 
o(n2)//iterate from 0 to n-1 and other from j=i+1 to n-1
optimal
using the merge sort algo
order of elements doesnt matter what matters is the smaller element on right
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count=0;
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr,0,N-1);
        return count;
    }
    long long int* mergeSort(long long arr[],long long low,long long high){
        if(low==high){
            long long int* ans=new long long int[1];
            ans[0]=arr[low];
            return ans;
        }
        long long mid=low+(high-low)/2;
        long long int* left=mergeSort(arr,low,mid);
        long long int* right=mergeSort(arr,mid+1,high);
        return mergeArrays(left,right,mid-low+1,high-mid);
    }
    long long int* mergeArrays(long long int* left,long long int* right,int n,int m){
        int i=0,j=0;
        long long int* ans=new long long int[n+m+1];
        int k=0;
        while(i<n and j<m){
            if(left[i]<right[j])
            ans[k++]=left[i++];
            else
            {ans[k++]=right[j++];
            count+=n-i;//inversion count right side element is smaller
                
            }
        }
            while(i<n)
            ans[k++]=left[i++];
            while(j<m)
            ans[k++]=right[j++];
            return ans;
        
    }

};