/*
https://leetcode.com/problems/combination-sum-ii/
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/
import java.util.*;

class Solution {

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(candidates); // required for duplicate skipping
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

            // skip duplicates at same recursion level
            if (i > ind && candidates[i] == candidates[i - 1]) continue;

            temp.add(candidates[i]);

            // i + 1 → element used only once
            solve(i + 1, target - candidates[i], candidates, temp, ans);

            temp.remove(temp.size() - 1); // backtrack
        }
    }
}