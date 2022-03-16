/*
LONGEST PALINDROMIC SUBSEQUENCE
https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1/
*/
class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n=A.size();
        string B=A;
        reverse(B.begin(),B.end());
        int dp[n+1][n+1];
         for(int i=0;i<=n;i++){
             for(int j=0;j<=n;j++){
                 if(i==0 or j==0)
                 dp[i][j]=0;
                 else if(A[i-1]==B[j-1])
                 dp[i][j]=dp[i-1][j-1]+1;
                 else
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
             }
         }
        return dp[n][n];
    }
};
