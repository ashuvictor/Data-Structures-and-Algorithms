
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
dp solution

long long sumSubstrings(string s){
       
       // your code here
       int n=s.size();
       long long dp[n];
       dp[0]=(s[0]-'0')%1000000007;
       long long sum=dp[0];
       for(int i=1;i<s.size();i++)
       {
        dp[i]=((i+1)*(s[i]-'0')+10*dp[i-1])%1000000007;   
        sum=(sum+dp[i])%1000000007;
       }
       return sum%1000000007;
   }

