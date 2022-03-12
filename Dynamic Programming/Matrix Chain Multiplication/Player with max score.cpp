Given an array arr of non-negative integers of size N, 2 players are playing a game. In each move, a player chooses an element from either end of the array, and the size of the array shrinks by one. Both players take alternate chances and the game continues until the size of the array becomes 0. Every time a player chooses an array element the array value is added to the player's score. At the end player with maximum score wins.
If player 1 starts the game, you have to predict whether player 1 will win the game or not. Both players will play optimally.
 

Example 1:

Input:
N = 3
arr[] = {2,6,3}
Output:
0 
Explanation:
Initially, player 1 can choose between 2 and 3. 
If he chooses 3 (or 2), then player 2 can choose 
from 2 (or 3) and 6. If player 2 chooses 6,
then player 1 will be left with 2 (or 3). 
So, final score of player 1 is 2 + 3 = 5,
and player 2 is 6. 
Hence, player 1 will never be the winner and 
output is 0.
https://practice.geeksforgeeks.org/problems/player-with-max-score/1/?category#
class Solution{   
public:
int dp[1002][1002];
   int solve(int i,int j,int arr[])
   {
       if(i>j)
       return 0;
       if(dp[i][j]!=-1)
       return dp[i][j];
       
       int x=arr[i]+min(solve(i+2,j,arr),solve(i+1,j-1,arr));
       int y=arr[j]+min(solve(i,j-2,arr),solve(i+1,j-1,arr));
       return dp[i][j]=max(x,y);
   }
    bool is1winner(int N,int arr[]) {
        
      int sum=0;
      dp[N][N];
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<N;i++)
      sum+=arr[i];
      
      int res=solve(0,N-1,arr);
      
      
      if(res>(sum-res))
      return true;
      else
      return false;
    }
};
