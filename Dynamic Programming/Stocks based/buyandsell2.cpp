You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include <bits/stdc++.h>
using namespace std;

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp) {
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if (ind == n) {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }

    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
    }

    // Store the calculated profit in the DP table and return it
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *Arr, int n) {
    // Create a DP table to memoize results
    vector<vector<long>> dp(n, vector<long>(2, -1));

    if (n == 0) {
        return 0;
    }

    long ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}

int main() {
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}




#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *Arr, int n) {
    // Create a DP table to memoize results
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    // Base condition: When we have no stocks left, the profit is 0.
    dp[n][0] = dp[n][1] = 0;

    long profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
}

int main() {
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}





#include <bits/stdc++.h>
using namespace std;

long getMaximumProfit(long *Arr, int n) {
    // Create two arrays to store the profits ahead of the current position (0 for not holding, 1 for holding)
    vector<long> ahead(2, 0);
    vector<long> cur(2, 0);

    // Base condition: When there are no stocks left, the profit is 0.
    ahead[0] = ahead[1] = 0;

    long profit;

    // Loop through the array in reverse order
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy] = profit;
        }

        ahead = cur; // Update the "ahead" array with the current values
    }

    // The maximum profit is stored in cur[0] after all calculations
    return cur[0];
}

int main() {
    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

    // Call the getMaximumProfit function and print the result
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

    return 0;
}



