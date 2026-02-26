https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

import java.util.HashMap;

class Solution {
    public int getPairsCount(int[] arr, int n, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int complement = k - arr[i];

            if (map.containsKey(complement)) {
                count += map.get(complement);
            }

            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }

        return count;
    }
}
