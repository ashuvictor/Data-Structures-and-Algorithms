
https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

Find minimum number of merge operations to make an array palindrome
Difficulty Level : Medium
Last Updated : 21 Jan, 2022
Given an array of positive integers. We need to make the given array a ‘Palindrome’.
 The only allowed operation is”merging” (of two adjacent elements). Merging two adjacent elements means replacing them with their sum. 
 
 The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.
To make any array a palindrome, we can simply apply merge operation n-1 times where n is the size of the array 
(because a single-element array is always palindromic
milar to single-character string). 
In that case, the size of array will be reduced to 1. But in this problem, we are asked to do it in the minimum number of operations.

// Returns minimum number of count operations
// required to make arr[] palindrome
int findMinOps(int arr[], int n)
{
    int ans = 0; // Initialize result
 
    // Start from two corners
    for (int i=0,j=n-1; i<=j;)
    {
        // If corner elements are same,
        // problem reduces arr[i+1..j-1]
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
 
        // If left element is greater, then
        // we merge right two elements
        else if (arr[i] > arr[j])
        {
            // need to merge from tail.
            j--;
            arr[j] += arr[j+1] ;
            ans++;
        }
 
        // Else we merge left two elements
        else
        {
            i++;
            arr[i] += arr[i-1];
            ans++;
        }
    }
 
    return ans;
}