Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.

https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1/


class Solution {

    public int countRev(String s) {

        // odd length cannot be balanced
        if (s.length() % 2 == 1)
            return -1;

        int open = 0, close = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '{') {
                open++;
            } else {
                if (open == 0)
                    close++;
                else
                    open--;
            }
        }

        // ceil(close/2) + ceil(open/2)
        int ans = (close + 1) / 2 + (open + 1) / 2;
        return ans;
    }
}