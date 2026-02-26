https://leetcode.com/problems/letter-combinations-of-a-phone-number/
import java.util.*;

class Solution {

    private void solve(String digits, StringBuilder output, int index,
                       List<String> ans, Map<Character, String> mp) {

        if (index >= digits.length()) {
            ans.add(output.toString());
            return;
        }

        char digit = digits.charAt(index);
        String value = mp.get(digit);

        for (int i = 0; i < value.length(); i++) {
            output.append(value.charAt(i));
            solve(digits, output, index + 1, ans, mp);
            output.deleteCharAt(output.length() - 1); // backtrack
        }
    }

    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits.length() == 0) return ans;

        Map<Character, String> mp = new HashMap<>();
        mp.put('2', "abc");
        mp.put('3', "def");
        mp.put('4', "ghi");
        mp.put('5', "jkl");
        mp.put('6', "mno");
        mp.put('7', "pqrs");
        mp.put('8', "tuv");
        mp.put('9', "wxyz");

        solve(digits, new StringBuilder(), 0, ans, mp);
        return ans;
    }
}