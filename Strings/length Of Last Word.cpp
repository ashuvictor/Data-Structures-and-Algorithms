
https://leetcode.com/problems/length-of-last-word/
iven a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

class Solution {
    public int lengthOfLastWord(String s) {
        int lastIndex = s.length() - 1;
        int result = 0;

        // Skip trailing spaces
        while (lastIndex >= 0 && s.charAt(lastIndex) == ' ')
            lastIndex--;

        // Count last word length
        while (lastIndex >= 0 && s.charAt(lastIndex) != ' ') {
            result++;
            lastIndex--;
        }

        return result;
    }
}


Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",


return 5 as length("World") = 5.


class Solution {
    public int lengthOfLastWord(String A) {
        int length = 0;

        for (int i = A.length() - 1; i >= 0; i--) {
            char c = A.charAt(i);

            if (Character.isWhitespace(c)) {
                if (length != 0) {
                    return length;
                }
            } else {
                length++;
            }
        }

        return length;
    }
}
