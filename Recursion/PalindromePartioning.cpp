/* Palindrome Partioning
https://leetcode.com/problems/palindrome-partitioning/
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/
import java.util.*;

class Solution {

    private boolean isPal(String s, int low, int high) {
        while (low < high) {
            if (s.charAt(low++) != s.charAt(high--))
                return false;
        }
        return true;
    }

    private void solve(int start, String s,
                       List<String> temp,
                       List<List<String>> ans) {

        if (start == s.length()) {
            ans.add(new ArrayList<>(temp));
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (isPal(s, start, end)) {
                temp.add(s.substring(start, end + 1));
                solve(end + 1, s, temp, ans);
                temp.remove(temp.size() - 1); // backtrack
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>();
        solve(0, s, new ArrayList<>(), ans);
        return ans;
    }
}