An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

 

Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)
            return false;
        if(n==1)
            return true;
        while(n%2==0) n=n/2;
        while(n%3==0) n=n/3;
        while(n%5==0) n=n/5;
        return n==1;
    }
};

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 https://leetcode.com/problems/ugly-number-ii/

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        int p1=0,p2=0,p3=0;
      for(int i=1;i<n;i++){
          int twomultiple=dp[p1]*2;
          int threemultiple=dp[p2]*3;
          int fivemultiple=dp[p3]*5;
          dp[i]=min(twomultiple,min(threemultiple,fivemultiple));
          if(dp[i]==twomultiple)
              p1++;
          if(dp[i]==threemultiple)
              p2++;
          if(dp[i]==fivemultiple)
              p3++;
      }
        return dp[n-1];
    }
};