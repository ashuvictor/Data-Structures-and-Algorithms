/* difference is 1
https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1/?page=2&difficulty[]=0&category[]=Dynamic%20Programming&sortBy=submissions
Given an array A[] of size N, find the longest subsequence such that difference between adjacent elements is one.
*/
class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        int dp[N]={0};
        int max_val=1;
        dp[0]=1;
        for(int i=1;i<N;i++){
            for(int j=i-1;j>=0;j--){
                if(abs(A[i]-A[j])==1){
                    dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]+=1;
            max_val=max(dp[i],max_val);
        }
    
        return max_val;
    }
};