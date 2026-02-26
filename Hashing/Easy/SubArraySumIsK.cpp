/*Given an array of integers nums and an integer k,
 return the total number of subarrays whose sum equals to k.
 https://leetcode.com/problems/subarray-sum-equals-k/
 */
 import java.util.*;

class Solution {
    public int subarraySum(int[] nums, int k) {
        int ans = 0;
        Map<Integer, Integer> map = new HashMap<>();

        map.put(0, 1); // base case
        int sum = 0;

        for (int num : nums) {
            sum += num;

            if (map.containsKey(sum - k)) {
                ans += map.get(sum - k);
            }

            map.put(sum, map.getOrDefault(sum, 0) + 1);
        }

        return ans;
    }
}
