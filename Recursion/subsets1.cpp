/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
https://leetcode.com/problems/subsets/
*/
import java.util.*;

class Solution {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        int possible = 1 << n; // 2^n

        for (int i = 0; i < possible; i++) {
            List<Integer> temp = new ArrayList<>();

            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    temp.add(nums[j]);
                }
            }
            ans.add(temp);
        }

        return ans;
    }
}
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(0, nums, new ArrayList<>(), ans);
        return ans;
    }

    private void backtrack(int i, int[] nums, List<Integer> curr, List<List<Integer>> ans) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(curr));
            return;
        }

        // include
        curr.add(nums[i]);
        backtrack(i + 1, nums, curr, ans);

        // exclude
        curr.remove(curr.size() - 1);
        backtrack(i + 1, nums, curr, ans);
    }
}