/*Sum of all substrings of a number 
https://practice.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1*/
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
       long n=s.size(); 
      long long dp[n+1];
     dp[0]=0;
     long mod=1e9+7;
     dp[1]=s[0]-'0';
     long long res=dp[1];
     for(int i=2;i<=n;i++){
         dp[i]=(dp[i-1]*10)%mod+((s[i-1]-'0')*i)%mod;
         res=(res%mod+dp[i]%mod)%mod;
     }
     return res;
    }
};