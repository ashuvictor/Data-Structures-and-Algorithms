
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"


import java.util.*;

class Solution {

    private int minLen(String[] strs) {
        int ans = strs[0].length();

        for (int i = 1; i < strs.length; i++) {
            ans = Math.min(ans, strs[i].length());
        }

        return ans;
    }

    public String longestCommonPrefix(String[] strs) {
        int sz = minLen(strs);
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < sz; i++) {
            char current = strs[0].charAt(i);

            for (int j = 0; j < strs.length; j++) {
                if (strs[j].charAt(i) != current)
                    return result.toString();
            }

            result.append(current);
        }

        return result.toString();
    }
}



BEST
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";

        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);

            for (int j = 1; j < strs.length; j++) {
                if (i == strs[j].length() || strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
        }

        return strs[0];
    }
}
