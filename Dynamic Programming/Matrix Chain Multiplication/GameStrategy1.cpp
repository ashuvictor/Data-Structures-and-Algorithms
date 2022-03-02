/*
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Example 1:

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)
*/

/*SOMETIMES YOU DO THINGS DO THE BEST
,SOMETIMES THINGS HAPPEN TO YOU ASSUME THE WORST
*/
class Solution{
    public:
   int dp[1001][1001];
   int solve(int i,int j,int a[]){
       if(i>j)
       return 0;
       if(dp[i][j]!=-1)
       return dp[i][j];
       int x=a[i]+min(solve(i+2,j,a),solve(i+1,j-1,a));
       int y=a[j]+min(solve(i,j-2,a),solve(i+1,j-1,a));
       return dp[i][j]=max(x,y);
   }
    long long maximumAmount(int arr[], int n){
        dp[n][n];
       memset(dp,-1,sizeof(dp));
       return solve(0,n-1,arr);
    }
};