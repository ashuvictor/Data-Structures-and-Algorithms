
https://leetcode.com/problems/split-a-string-in-balanced-strings/
Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it in the maximum amount of balanced strings.

Return the maximum amount of split balanced strings.

 

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

class Solution {
public:
    int balancedStringSplit(string s) {
        int total=0;
        int ans=0;
        for(auto x:s)
        {
            if(x=='L')
                total++;
            else
                total--;
            if(total==0)
                ans++;
        }
        return ans;
    }
};