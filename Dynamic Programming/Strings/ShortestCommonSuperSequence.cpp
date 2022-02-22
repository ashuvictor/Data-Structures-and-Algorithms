/*Shortest Common Supersequence 
https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.
*/
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
       int dp[m+1][n+1];
       for(int i=0;i<=m;i++){
           for(int j=0;j<=n;j++){
               if(i==0 or j==0)
               dp[i][j]=0;
               else if(X[i-1]==Y[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];}
                   else
                   dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
               }
           }
        return m+n-dp[m][n];}
      
    
};