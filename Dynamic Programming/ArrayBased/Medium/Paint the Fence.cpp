

Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.


//Recursive Approach
class Solution{
    public:
    long mod=1000000007;
    unordered_map<long long int,long long int> dp;
    long long countWays(int n, int k){
        if(n==1) return k;
        if(n==2) return ((long long)k*(long long)k)%mod;
        if(n==0 or k==0) return 0;
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        long long ans=((long long)(k-1)*(countWays(n-1,k)%mod+countWays(n-2,k)%mod)%mod)%mod;
        return dp[n]=ans%mod;
    }
};


// C++ program for Painting Fence Algorithm
// optimised version

#include <bits/stdc++.h>
using namespace std;

// Returns count of ways to color k posts
long countWays(int n, int k)
{
	long dp[n + 1];
	memset(dp, 0, sizeof(dp));
	long long mod = 1000000007;

	dp[1] = k;
	dp[2] = k * k;

	for (int i = 3; i <= n; i++) {
		dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
	}

	return dp[n];
}

// Driver code
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
         if (n == 0)
        return 0;
        if(n == 1)
         return k;
        int modulo=1e9+7;
        long long same=k;
        long long diff=k*(k-1);
        long long total=same+diff;
        for(long long i=3;i<=n;i++){
            same=(diff)%modulo;
            diff=(total*(k-1))%modulo;
            total=(same+diff)%modulo;
            
        }
        return total%modulo;
    }
};