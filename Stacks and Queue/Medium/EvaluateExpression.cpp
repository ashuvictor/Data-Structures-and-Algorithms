//https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#
import java.util.*;

class Solution {

    public int evaluatePostfix(String S) {
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < S.length(); i++) {
            char ch = S.charAt(i);

            if (ch >= '0' && ch <= '9') {
                stack.push(ch - '0');
            } else {
                int x = stack.pop(); // top
                int y = stack.pop(); // second top

                switch (ch) {
                    case '+': stack.push(y + x); break;
                    case '-': stack.push(y - x); break;
                    case '*': stack.push(y * x); break;
                    case '/': stack.push(y / x); break;
                }
            }
        }

        return stack.peek();
    }
}
//PREFIX EXPRESSION
import java.util.*;

class Solution {

    public int evaluatePrefix(String S) {
        Deque<Integer> stack = new ArrayDeque<>();

        int n = S.length();

        for (int i = n - 1; i >= 0; i--) {
            char ch = S.charAt(i);

            // digit
            if (Character.isDigit(ch)) {
                stack.push(ch - '0');
            } else {
                int x = stack.pop();
                int y = stack.pop();

                switch (ch) {
                    case '+': stack.push(x + y); break;
                    case '-': stack.push(x - y); break;
                    case '*': stack.push(x * y); break;
                    case '/': stack.push(x / y); break;
                }
            }
        }

        return stack.peek();
    }
}