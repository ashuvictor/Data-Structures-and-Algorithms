https://leetcode.com/problems/find-all-anagrams-in-a-string/
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

pproach 1: Brute Force (Finding all substrings of size (p) and cheacking if it is anagram or not)
Status: TLE
import java.util.*;

class Solution {
    private boolean isAnagram(String s, String t) {
        char[] a = s.toCharArray();
        char[] b = t.toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);
        return Arrays.equals(a, b);
    }

    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> idx = new ArrayList<>();
        int n = s.length();
        int m = p.length();

        for (int i = 0; i <= n - m; i++) {
            String temp = s.substring(i, i + m);
            if (isAnagram(temp, p)) {
                idx.add(i);
            }
        }

        return idx;
    }
}




import java.util.*;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();

        if (s.length() < p.length()) return res;

        int[] count = new int[26];

        // Count p chars
        for (char c : p.toCharArray()) {
            count[c - 'a']++;
        }

        int left = 0, right = 0, needed = p.length();

        while (right < s.length()) {
            if (count[s.charAt(right) - 'a']-- > 0) {
                needed--;
            }
            right++;

            if (needed == 0) res.add(left);

            if (right - left == p.length()) {
                if (count[s.charAt(left) - 'a']++ >= 0) {
                    needed++;
                }
                left++;
            }
        }

        return res;
    }
}
