// Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


// Example 1:


// Input: N = 4, sum = 2
// arr[] = {-2, 0, 1, 3}
// Output:  2
// Explanation: Below are triplets with 
// sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
import java.util.*;

class Solution {

    public long countTriplets(long[] arr, int n, long sum) {
        long ans = 0;

        Arrays.sort(arr);

        for (int k = 0; k < n - 2; k++) {
            int i = k + 1;
            int j = n - 1;

            while (i < j) {
                long s = arr[k] + arr[i] + arr[j];

                if (s < sum) {
                    ans += (j - i); // all pairs between i and j valid
                    i++;
                } else {
                    j--;
                }
            }
        }

        return ans;
    }
}