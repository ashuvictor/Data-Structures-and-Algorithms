/* Form a palindrome
https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd
*/
class Solution{
  public:
    int countMin(string str){
    //complete the function here
    string str1=str;
    reverse(str.begin(),str.end());
    int l=str.size();
    int dp[l+1][l+1];
    for(int i=0;i<=l;i++){
        for(int j=0;j<=l;j++){
            if(i==0 or j==0 )
            dp[i][j]=0;
            else if(str[i-1]==str1[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return l-dp[l][l];
    }
};