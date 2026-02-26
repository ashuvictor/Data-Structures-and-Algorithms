/*
https://leetcode.com/problems/combination-sum/
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
*/
import java.util.*;

class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        solve(0, target, candidates, new ArrayList<>(), ans);
        return ans;
    }

    private void solve(int ind, int target, int[] candidates,
                       List<Integer> temp, List<List<Integer>> ans) {

        if (target < 0) return;

        if (target == 0) {
            ans.add(new ArrayList<>(temp));
            return;
        }

        for (int i = ind; i < candidates.length; i++) {
            temp.add(candidates[i]);
            // reuse allowed → pass i (not i+1)
            solve(i, target - candidates[i], candidates, temp, ans);
            temp.remove(temp.size() - 1); // backtrack
        }
    }
}