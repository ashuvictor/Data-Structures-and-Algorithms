/*tiling a floor
Given a value N. In how many ways you can construct a grid of size N x 4 using tiles of size 1 x 4.

https://practice.geeksforgeeks.org/problems/number-of-ways2552/1

Example 1:

Input: N = 1
Output: 1
Explaination: There is only one way.

Example 2:

Input: N = 4
Output: 2
Explaination: The first way can be when all 
the 1 x 4 tiles are arranged horizontally. 
Second way can be when all the 1 x 4 tiles 
are arranged vertically.
*/
class Solution{
public:
    long long int arrangeTiles(int N){
        // code here
        long long int dp[N+1]={0};
        dp[0]=dp[1]=dp[2]=dp[3]=1;
        for(int i=4;i<=N;i++)
        dp[i]=dp[i-1]+dp[i-4];
        return dp[N];
    }
};