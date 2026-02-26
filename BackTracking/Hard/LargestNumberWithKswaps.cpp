https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
import java.util.*;

class Solution {

    void solve(char[] str, int n, int k, StringBuilder ans, int index) {
        if (k == 0 || index == n)
            return;

        char maxChar = str[index];

        // find max digit in remaining substring
        for (int i = index + 1; i < n; i++) {
            if (str[i] > maxChar)
                maxChar = str[i];
        }

        // reduce swap count only if we found bigger digit
        if (maxChar != str[index])
            k--;

        // try all positions having max digit
        for (int i = n - 1; i >= index; i--) {
            if (str[i] == maxChar) {

                swap(str, index, i);

                String current = new String(str);
                if (current.compareTo(ans.toString()) > 0) {
                    ans.setLength(0);
                    ans.append(current);
                }

                solve(str, n, k, ans, index + 1);

                swap(str, index, i); // backtrack
            }
        }
    }

    void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public String findMaximumNum(String str, int k) {
        StringBuilder ans = new StringBuilder(str);
        char[] arr = str.toCharArray();
        solve(arr, arr.length, k, ans, 0);
        return ans.toString();
    }
}