Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.


Example 1:

Input:
N = 6
Arr[] = {6, 8, 4, 5, 2, 3}
Output: 604
Explanation: The minimum sum is formed 
by numbers 358 and 246.

Example 2:

Input:
N = 5
Arr[] = {5, 3, 0, 7, 4}
Output: 82
Explanation: The minimum sum is 
formed by numbers 35 and 047.

import java.util.*;

class Solution {

    // String addition (big number addition)
    private String sumString(String str1, String str2) {
        // Ensure str2 is longer
        if (str1.length() > str2.length()) {
            String temp = str1;
            str1 = str2;
            str2 = temp;
        }

        StringBuilder res = new StringBuilder();
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;
        int carry = 0;

        // Add common parts
        for (int i = n1 - 1; i >= 0; i--) {
            int sum = (str1.charAt(i) - '0') +
                      (str2.charAt(i + diff) - '0') + carry;
            res.append(sum % 10);
            carry = sum / 10;
        }

        // Remaining digits of str2
        for (int i = n2 - n1 - 1; i >= 0; i--) {
            int sum = (str2.charAt(i) - '0') + carry;
            res.append(sum % 10);
            carry = sum / 10;
        }

        if (carry > 0) res.append(carry);

        return res.reverse().toString();
    }

    public String solve(int[] arr, int n) {
        Arrays.sort(arr);

        StringBuilder num1 = new StringBuilder();
        StringBuilder num2 = new StringBuilder();

        for (int i = 0; i < n; i++) {
            int num = arr[i];

            if (i % 2 == 0) {
                if (num == 0 && num1.length() == 0) continue;
                num1.append(num);
            } else {
                if (num == 0 && num2.length() == 0) continue;
                num2.append(num);
            }
        }

        return sumString(num1.toString(), num2.toString());
    }
}