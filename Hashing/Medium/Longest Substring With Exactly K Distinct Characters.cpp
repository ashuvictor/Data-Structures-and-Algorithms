C++ Code (Using sliding window algorithm)
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.


Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.
https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#
 

import java.util.*;

class Solution {
    public int longestKSubstr(String s, int k) {
        int i = 0, j = 0;
        int result = -1;
        Map<Character, Integer> map = new HashMap<>();

        while (j < s.length()) {
            char c = s.charAt(j);
            map.put(c, map.getOrDefault(c, 0) + 1);

            if (map.size() < k) {
                j++;
            }
            else if (map.size() == k) {
                result = Math.max(result, j - i + 1);
                j++;
            }
            else { // map.size() > k
                while (map.size() > k) {
                    char leftChar = s.charAt(i);
                    map.put(leftChar, map.get(leftChar) - 1);

                    if (map.get(leftChar) == 0) {
                        map.remove(leftChar);
                    }
                    i++;
                }
                j++;
            }
        }

        return result;
    }
}