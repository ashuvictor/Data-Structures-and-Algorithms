


132. Palindrome Partitioning II

every string can have maximum n-1 partition
class Solution {

    private boolean isPalin(int l, int r, String s) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }

    private int solve(int i, int n, String str) {
        if (i == n) return 0;

        int minCost = Integer.MAX_VALUE;

        for (int j = i; j < str.length(); j++) {
            if (isPalin(i, j, str)) {
                int cost = 1 + solve(j + 1, n, str);
                minCost = Math.min(minCost, cost);
            }
        }

        return minCost;
    }

    public int minCut(String s) {
        int n = s.length();
        return solve(0, n, s) - 1;
    }
}
import java.util.Arrays;

class Solution {

    private boolean isPalin(int l, int r, String s) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }
        return true;
    }

    private int solve(int i, int n, String str, int[] dp) {
        // if whole remaining string is palindrome
        if (i >= n || isPalin(i, n - 1, str))
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int minCost = Integer.MAX_VALUE;

        for (int j = i; j < n; j++) {
            if (isPalin(i, j, str)) {
                int cost = 1 + solve(j + 1, n, str, dp);
                minCost = Math.min(minCost, cost);
            }
        }

        return dp[i] = minCost;
    }

    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return solve(0, n, s, dp);
    }
}
import java.util.*;

class Solution {

    private boolean isPalin(int l, int r, String s) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) return false;
            l++;
            r--;
        }
        return true;
    }

    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];

        // dp[n] = 0 already

        for (int i = n - 1; i >= 0; i--) {
            int minCost = Integer.MAX_VALUE; // reset every i

            for (int j = i; j < n; j++) {
                if (isPalin(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    minCost = Math.min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1; // partitions → cuts
    }
}
1278. Palindrome Partitioning III

import java.util.*;

class Solution {

    private int[][] cost;
    private int[][] dp;

    private int costFun(String s, int l, int r) {
        if (l >= r) return 0;
        if (cost[l][r] != -1) return cost[l][r];

        return cost[l][r] =
                (s.charAt(l) != s.charAt(r) ? 1 : 0) +
                costFun(s, l + 1, r - 1);
    }

    private int solve(String s, int k, int pos, int n) {
        if (k == 0) return costFun(s, pos, n - 1);
        if (pos >= n) return Integer.MAX_VALUE / 2; // avoid overflow

        if (dp[pos][k] != -1) return dp[pos][k];

        int ans = (int) 1e6;

        for (int i = pos; i < n - 1; i++) {
            int left = costFun(s, pos, i);
            int right = solve(s, k - 1, i + 1, n);
            ans = Math.min(ans, left + right);
        }

        return dp[pos][k] = ans;
    }

    public int palindromePartition(String s, int k) {
        int n = s.length();
        cost = new int[n][n];
        dp = new int[n][k + 1];

        for (int[] row : cost) Arrays.fill(row, -1);
        for (int[] row : dp) Arrays.fill(row, -1);

        return solve(s, k - 1, 0, n);
    }
}


1745. Palindrome Partitioning IV

import java.util.*;

class Solution {

    private int[][] pali;

    private int isPali(String s, int l, int r) {
        if (l >= r) return 1;
        if (pali[l][r] != -1) return pali[l][r];

        if (s.charAt(l) == s.charAt(r)) {
            return pali[l][r] = isPali(s, l + 1, r - 1);
        }
        return pali[l][r] = 0;
    }

    public boolean checkPartitioning(String s) {
        int n = s.length();
        pali = new int[n][n];

        for (int[] row : pali) Arrays.fill(row, -1);

        // split into 3 palindromes
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j <= i; j++) {

                if (isPali(s, 0, j - 1) == 1 &&
                    isPali(s, j, i) == 1 &&
                    isPali(s, i + 1, n - 1) == 1) {
                    return true;
                }
            }
        }
        return false;
    }
}