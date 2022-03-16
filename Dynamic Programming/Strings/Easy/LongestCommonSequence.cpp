/*LONGEST COMMON SEQUENCE
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
*/
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
      int dp[x+1][y+1];
      for(int i=0;i<=x;i++){
          for(int j=0;j<=y;j++){
              if(i==0 or j==0)
              dp[i][j]=0;
              else if(s1[i-1]==s2[j-1])
              dp[i][j]=dp[i-1][j-1]+1;
          else
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              
          }
      }
      return dp[x][y];
    }
};
