

https://leetcode.com/problems/powx-n/
https://www.interviewbit.com/problems/implement-power-function/
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
class Solution {

    public double myPow(double x, int n) {
        double ans = 1.0;
        boolean flag = false;

        long nn = n; // prevent overflow (important for Integer.MIN_VALUE)

        if (n < 0) {
            flag = true;
            nn = -nn;
        }

        while (nn > 0) {
            if ((nn & 1) == 1) {
                ans *= x;
                nn -= 1;
            } else {
                x *= x;
                nn >>= 1;
            }
        }

        return flag ? 1.0 / ans : ans;
    }
}



public class Solution {

    public int pow(int x, int n, int d) {
        if (n == 0)
            return 1 % d;

        long ans = 1;
        long base = x;

        while (n > 0) {
            if ((n % 2) == 1) {
                ans = (ans * base) % d;
                n--;
            } else {
                base = (base * base) % d;
                n /= 2;
            }
        }

        // Fix negative modulo
        if (ans < 0)
            ans = (ans + d) % d;

        return (int) ans;
    }
}