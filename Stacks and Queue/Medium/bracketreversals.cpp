
Minimum Cost To Make String Valid
Difficulty: MEDIUM
Contributed By
Arshit Babariya
|
Level 1
Avg. time to solve
20 min
Success Rate
80%
Problem Statement
Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced. Formally for each opening bracket, there must be a closing bracket right to it.
For Example:
“{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.
Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.
For Example:
Minimum operations to make ‘STR’ =  “{{“ valid is 1.
In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’. The ‘STR’ now becomes "{}" which is a valid string.

Note:
Return -1 if it is impossible to make ‘STR’ valid.

import java.util.*;

class Solution {

    public int findMinimumCost(String str) {

        // odd length → impossible
        if (str.length() % 2 == 1)
            return -1;

        Deque<Character> stack = new ArrayDeque<>();

        for (char ch : str.toCharArray()) {

            if (ch == '{') {
                stack.push(ch);
            } else {
                // closing brace
                if (!stack.isEmpty() && stack.peek() == '{') {
                    stack.pop();
                } else {
                    stack.push(ch);
                }
            }
        }

        // count invalid braces
        int open = 0, close = 0;

        while (!stack.isEmpty()) {
            if (stack.pop() == '{')
                open++;
            else
                close++;
        }

        return (open + 1) / 2 + (close + 1) / 2;
    }
}





public int findMinimumCost(String str) {
    if (str.length() % 2 == 1) return -1;

    int open = 0, reversals = 0;

    for (char ch : str.toCharArray()) {
        if (ch == '{') {
            open++;
        } else {
            if (open > 0) {
                open--; // match
            } else {
                reversals++;
                open = 1; // simulate reversing }
            }
        }
    }

    return reversals + open / 2;
}