Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
https://leetcode.com/problems/counting-bits/
 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i=0;i<=n;i++){
            int cnt=0;
            int n=i;
            while(n){
                n=n&(n-1);
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
                dp[i]=dp[i/2];
            else
                dp[i]=dp[i/2]+1;
        }
        return dp;
    }
};