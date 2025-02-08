714. Best Time to Buy and Sell Stock with Transaction Fee

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.




#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int> &Arr, int ind, int buy, int n, int fee, vector<vector<int>> &dp) {
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind == n) return 0;
    
    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
        
    int profit;
    
    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, fee, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, fee, dp));
    }
    
    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, fee, dp), Arr[ind] - fee + getAns(Arr, ind + 1, 0, n, fee, dp));
    }
    
    // Store the computed profit in the DP array
    return dp[ind][buy] = profit;
}

int maximumProfit(int n, int fee, vector<int> &Arr) {
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    if (n == 0) return 0; // Edge case: No stocks to trade.
    
    int ans = getAns(Arr, 0, 0, n, fee, dp);
    return ans;
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;
                                 
    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}






#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int n, int fee, vector<int>& Arr) {
    if (n == 0) return 0; // Edge case: No stocks to trade.

    // Create a 2D DP array with dimensions (n+1) x 2, initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] - fee + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][0]; // Return the maximum profit for buying.
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}






#include <bits/stdc++.h>
using namespace std;

int maximumProfit(int n, int fee, vector<int>& Arr) {
    if (n == 0) return 0; // Edge case: No stocks to trade.

    vector<long> ahead(2, 0); // To track maximum profit one step ahead
    vector<long> cur(2, 0);   // To track current maximum profit

    // Initialize both ahead[0] and ahead[1] to 0 as the base condition
    ahead[0] = ahead[1] = 0;

    long profit;

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], Arr[ind] - fee + ahead[0]);
            }
            cur[buy] = profit;
        }

        ahead = cur;
    }
    return cur[0]; // Return the maximum profit for buying.
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;

    cout << "The maximum profit that can be generated is " << maximumProfit(n, fee, prices) << endl;
    return 0;
}

