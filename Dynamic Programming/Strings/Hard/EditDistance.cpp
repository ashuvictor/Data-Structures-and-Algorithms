/*https://practice.geeksforgeeks.org/problems/edit-distance3702/1
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
*/

class Solution {
  public:
    int dp[1001][1001];
    int solve(string s,string t,int m,int n){
        if(m==-1)
        return n+1;
        if(n==-1)
        return m+1;
        if(dp[m][n]!=-1)
        return dp[m][n];
        if(s[m]==t[n])
        return dp[m][n]=solve(s,t,m-1,n-1);
        int a=solve(s,t,m-1,n-1);//replace
        int b=solve(s,t,m,n-1);//insert
        int c=solve(s,t,m-1,n);//remove
        return dp[m][n]=1+min(a,min(b,c));
    }
    int editDistance(string s, string t) {
       memset(dp,-1,sizeof(dp));
       int m=s.length();
       int n=t.length();
       return solve(s,t,m-1,n-1);
    }
};

// A Dynamic Programming based C++ program to find minimum 
// number operations to convert str1 to str2 
#include <bits/stdc++.h> 
using namespace std; 

// Utility function to find the minimum of three numbers 
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

int editDistDP(string str1, string str2, int m, int n) 
{ 
	// Create a table to store results of subproblems 
	int dp[m + 1][n + 1]; 

	// Fill d[][] in bottom up manner 
	for (int i = 0; i <= m; i++) { 
		for (int j = 0; j <= n; j++) { 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i == 0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j == 0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (str1[i - 1] == str2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1]; 

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
								dp[i - 1][j], // Remove 
								dp[i - 1][j - 1]); // Replace 
		} 
	} 

	return dp[m][n]; 
} 

// Driver program 
int main() 
{ 
	// your code goes here 
	string str1 = "sunday"; 
	string str2 = "saturday"; 

	cout << editDistDP(str1, str2, str1.length(), str2.length()); 

	return 0; 
} 