/*  Maximum dot product
https://practice.geeksforgeeks.org/problems/maximize-dot-product2649/1/
Given two arrays A and B of positive integers of size N and M where N >= M, the task is to maximize the dot product by inserting zeros in the second array but you cannot disturb the order of elements.

Dot Product of array A and B of size N is A[0]*B[0] + A[1]*B[1]+....A[N]*B[N].

*/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		
	public:
	int maxDotProduct(int n, int m, int A[], int B[]) 
	{ 
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
	    for(int j=0;j<=m;j++){
	        if(j==0)
	        dp[i][j]=0;
	        else if(i==0)
	        dp[i][j]=INT_MIN;
	        else
	        dp[i][j]=max(A[i-1]*B[j-1]+dp[i-1][j-1],dp[i-1][j]);
	    }
	}
    
	return dp[n][m];
	} 
};


