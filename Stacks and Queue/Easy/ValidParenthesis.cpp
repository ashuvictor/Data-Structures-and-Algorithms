// https://leetcode.com/problems/valid-parentheses/


import java.util.*;

class Solution {

    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (char ch : s.toCharArray()) {

            // push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                // closing bracket without opening
                if (stack.isEmpty())
                    return false;

                char top = stack.pop();

                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    continue;
                } else {
                    return false;
                }
            }
        }

        return stack.isEmpty();
    }
}