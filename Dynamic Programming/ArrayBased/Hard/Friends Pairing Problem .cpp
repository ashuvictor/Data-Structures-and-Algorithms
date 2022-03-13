/*Friends Pairing Problem
https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1 */
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
         int mod=1e9+7;
        long long int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]+((i-1)*dp[i-2])%mod)%mod;
        }
        return dp[n]%mod;
    }
};    
 
