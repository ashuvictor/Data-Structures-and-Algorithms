/*https://leetcode.com/problems/subsets-ii/
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
import java.util.*;

class Solution {

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums); // sort to handle duplicates
        solve(0, nums, new ArrayList<>(), ans);
        return ans;
    }

    private void solve(int ind, int[] nums, List<Integer> temp, List<List<Integer>> ans) {
        ans.add(new ArrayList<>(temp));

        for (int i = ind; i < nums.length; i++) {
            // skip duplicates
            if (i > ind && nums[i] == nums[i - 1]) continue;

            temp.add(nums[i]);
            solve(i + 1, nums, temp, ans);
            temp.remove(temp.size() - 1); // backtrack
        }
    }
}