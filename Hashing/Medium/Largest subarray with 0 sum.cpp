Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1/#
import java.util.*;

class Solution {
    public int maxLen(int[] A, int n) {
        Map<Integer, Integer> map = new HashMap<>();

        map.put(0, -1); // important base case
        int sum = 0;
        int len = 0;

        for (int i = 0; i < n; i++) {
            sum += A[i];

            if (!map.containsKey(sum)) {
                map.put(sum, i); // store first occurrence
            } else {
                len = Math.max(len, i - map.get(sum));
            }
        }

        return len;
    }
}
