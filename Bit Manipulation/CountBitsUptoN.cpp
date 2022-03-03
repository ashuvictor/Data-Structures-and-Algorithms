/*

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
https://leetcode.com/problems/counting-bits/
*/
 //time -o(nlog2(n))
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
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++){
            if(i%2==0)
                ans[i]=ans[i/2];
            else
                ans[i]=ans[i/2]+1;
        }
        return ans;
    }
};