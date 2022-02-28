/* Longest Repeating Subsequence
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences
 A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.
 */
 class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		 int dp[str.length()+1][str.length()+1];
		 for(int i=0;i<=str.length();i++){
		     for(int j=0;j<=str.length();j++){
		         if(i==0 or j==0)
		         dp[i][j]=0;
		         else if(i!=j and str[i-1]==str[j-1])
		         dp[i][j]=1+dp[i-1][j-1];
		         else
		         dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		     }
		 }
		 return dp[str.length()][str.length()];
		}

};