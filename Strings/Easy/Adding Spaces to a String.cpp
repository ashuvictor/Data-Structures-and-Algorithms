
https://leetcode.com/problems/adding-spaces-to-a-string/
You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. Each space should be inserted before the character at the given index.

For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain "Enjoy Your Coffee".
Return the modified string after the spaces have been added.

 

Example 1:

Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
Output: "Leetcode Helps Me Learn"
Explanation: 
The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
We then place spaces before those characters.


class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder res = new StringBuilder();

        int i = 0, j = 0;

        while (i < s.length() && j < spaces.length) {
            if (i == spaces[j]) {
                res.append(' ');
                j++;
            }
            res.append(s.charAt(i));
            i++;
        }

        // Add remaining characters
        while (i < s.length()) {
            res.append(s.charAt(i));
            i++;
        }

        return res.toString();
    }
}



Why StringBuilder?

Using:

res += " "

creates new strings repeatedly ❌ (slow)

StringBuilder = O(n) efficient ✅

🧪 Example

Input:

s = "LeetcodeHelpsMeLearn"
spaces = [8,13,15]

Output:

"Leetcode Helps Me Learn"
⏱ Complexity

Time: O(n)

Space: O(n)

⚡ Cleaner Java Version (For-each style)
class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder sb = new StringBuilder();
        int spaceIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            if (spaceIndex < spaces.length && i == spaces[spaceIndex]) {
                sb.append(' ');
                spaceIndex++;
            }
            sb.append(s.charAt(i));
        }

        return sb.toString();
    }
}
