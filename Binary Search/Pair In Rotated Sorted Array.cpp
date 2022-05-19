
https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
Given an array that is sorted and then rotated around an unknown point. Find if the array has a pair with a given sum ‘x’. It may be assumed that all elements in the array are distinct.

Examples : 

Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
Output: true
There is a pair (6, 10) with sum 16

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
Output: true
There is a pair (26, 9) with sum 35

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
Output: false
There is no pair with sum 45.



The time complexity of the above solution is O(n). The step to find the pivot can be optimized to O(Logn) using the Binary Search approach discussed here.

How to count all pairs having sum x? 
The stepwise algorithm is:  

Find the pivot element of the sorted and the rotated array. The pivot element is the largest element in the array. The smallest element will be adjacent to it.
Use two pointers (say left and right) with the left pointer pointing to the smallest element and the right pointer pointing to largest element.
Find the sum of the elements pointed by both the pointers.
If the sum is equal to x, then increment the count. If the sum is less than x, then to increase sum move the left pointer to next position by incrementing it in a rotational manner. If the sum is greater than x, then to decrease sum move the right pointer to next position by decrementing it in rotational manner.
Repeat step 3 and 4 until the left pointer is not equal to the right pointer or until the left pointer is not equal to right pointer – 1.
Print final count.
// with sum equals to x.
bool pairInSortedRotated(int arr[], int n, int x)
{
    // Find the pivot element
    int i;
    for (i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            break;
    int l = (i+1)%n;  // l is now index of smallest element
    int r = i;        // r is now index of largest element
 
    // Keep moving either l or r till they meet
    while (l != r)
    {
         // If we find a pair with sum x, we return true
         if (arr[l] + arr[r] == x)
              return true;
 
         // If current pair sum is less, move to the higher sum
         if (arr[l] + arr[r] < x)
              l = (l + 1)%n;
         else  // Move to the lower sum side
              r = (n + r - 1)%n;
    }
    return false;
}
 