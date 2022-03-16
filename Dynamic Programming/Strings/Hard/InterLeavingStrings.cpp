Given A, B, C, find whether C is formed by the interleaving of A and B.

Input Format:*

The first argument of input contains a string, A.
The second argument of input contains a string, B.
The third argument of input contains a string, C.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= length(A), length(B), length(C) <= 150
Examples:

Input 1:
    A = "aabcc"
    B = "dbbca"
    C = "aadbbcbcac"

Output 1:
    1
    
Explanation 1:
    "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)
https://www.interviewbit.com/problems/interleaving-strings/
https://practice.geeksforgeeks.org/problems/interleaved-strings/1
https://leetcode.com/problems/interleaving-string/submissions/
bool solve(int i,int j,int k,string A,string B,string C)
{
    if(k==C.size() and i==A.size() and j==B.size())
    return true;
    if(k==C.size())
    return false;
    if(i==A.size() and j==B.size())
    return false;
    if(i==A.size())
    {
        if(B[j]==C[k])
        return solve(i,j+1,k+1,A,B,C);
        else
        return false;
    }
    else if(j==B.size())
    {
        if(A[i]==C[k])
        return solve(i+1,j,k+1,A,B,C);
        else
        return false;
    }
    else if(A[i]==C[k] and B[j]==C[k])
    return solve(i+1,j,k+1,A,B,C) || solve(i,j+1,k+1,A,B,C);
    else if(A[i]==C[k])
    return solve(i+1,j,k+1,A,B,C);
    else if(B[j]==C[k])
    return solve(i,j+1,k+1,A,B,C);
    else
    return false;
}
int Solution::isInterleave(string A, string B, string C) {
    return solve(0,0,0,A,B,C); 

}


class Solution{
  public:
  int dp[1001][1001];
    /*You are required to complete this method */
    bool solve(string A,string B,string C,int n,int m ,int len){
        if(len==0)
        return 1;
        if(dp[n][m]!=-1)
        return dp[n][m];
        int a=0,b=0;
        if((n-1)>=0 and A[n-1]==C[len-1])
        a=solve(A,B,C,n-1,m,len-1);
        if((m-1)>=0 and B[m-1]==C[len-1])
        b=solve(A,B,C,n,m-1,len-1);
        
        return dp[n][m]=a or b;
    }
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n=A.length();
        int m=B.length();
        int len=C.length();
        if(len!=n+m)
        return false;
        dp[n][m];
        memset(dp,-1,sizeof(dp));
        return solve(A,B,C,n,m,len);
    }
class Solution{
  public:

    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n=A.length();
        int m=B.length();
        int len=C.length();
        if(len!=n+m)
        return false;
       bool dp[n+1][m+1];
       for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=m;j++){
               if(i==0 or j==0)
               dp[i][j]=true;
               else{
                   int a=0,b=0;
                   if((i-1)>=0 and A[i-1]==C[i+j-1])
                   a=dp[i-1][j];
                   if((j-1)>=0  and B[j-1]==C[i+j-1])
                   b=dp[i][j-1];
                   dp[i][j]=a or b;
               }
           }
       }
       return dp[n][m];
    }

};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        // If sum of length of strings not equal to output string, return false
        if(n1+n2 != n3) return false;
        
        // Create a dp array
        int dp[n1+1][n2+1];
        dp[0][0] = true;
        
        // Check for interleaving when j=0
        for(int i=1;i<=n1;i++)
            dp[i][0] = dp[i-1][0] and s1[i-1] == s3[i-1];
        
        // Check for interleaving when i=0
        for(int j=1;j<=n2;j++)
            dp[0][j] = dp[0][j-1] and s2[j-1] == s3[j-1];
        
        // Check for interleaving while updating dp array
        for(int i=1;i<=n1;i++)
            for(int j=1; j<=n2; j++)
                dp[i][j] = (dp[i-1][j] and s1[i-1]==s3[i+j-1]) or (dp[i][j-1] and s2[j-1] == s3[i+j-1]);
            
        return dp[n1][n2];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
      if (n1 + n2 != n3) { return false; }
      vector<bool> trans(n2+1);
      trans[0] = true;
      for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
          int p = i+j-1;
          if (i > 0) { trans[j] = trans[j] && s1[i-1] == s3[p]; }
          if (j > 0) { trans[j] = trans[j] || trans[j-1] && s2[j-1] == s3[p]; }
        }
      }
      return trans[n2];
    }
};