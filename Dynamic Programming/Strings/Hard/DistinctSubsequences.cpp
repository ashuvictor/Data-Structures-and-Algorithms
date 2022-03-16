Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
Example :

Input 1:
    A = "abc"
    B = "abc"
    
Output 1:
    1

Explanation 1:
    Both the strings are equal.

Input 2:
    A = "rabbbit" 
    B = "rabbit"

Output 2:
    3

Explanation 2:
    These are the possible removals of characters:
        => A = "ra_bbit" 
        => A = "rab_bit" 
        => A = "rabb_it"
        
    Note: "_" marks the removed character.
https://www.interviewbit.com/problems/distinct-subsequences/

int dp[701][701];
int solve(int i,int j,string A,string B)
{
    if(j==B.size()) return 1;
    if(i==A.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(A[i]==B[j])       //characters are same then we have two choices
    {
        int case1=solve(i+1,j+1,A,B);
        int case2=solve(i+1,j,A,B);
        return dp[i][j]=case1+case2;
    }
    else
    {
        return dp[i][j]=solve(i+1,j,A,B);
    }
    
}
int Solution::numDistinct(string A, string B) {
memset(dp,-1,sizeof(dp));
    return solve(0,0,A,B);
    
}

https://leetcode.com/problems/distinct-subsequences/submissions/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=t.size();
        int m=s.size();
       vector<vector<unsigned long long >>dp(n+1,vector<unsigned long long >(m+1,0));
        for(int j=0;j<=m;j++)
            dp[0][j]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i-1]==s[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};