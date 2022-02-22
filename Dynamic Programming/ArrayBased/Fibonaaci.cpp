/*https://practice.geeksforgeeks.org/problems/reach-the-nth-point5433/1/
Reach the Nth point
*/
class Solution{
	public:
		int nthPoint(int n){
		   int dp[n+1]={0};
		   dp[0]=1;
		   dp[1]=1;
		   int mod=1e9+7;
		   for(int i=2;i<=n;i++)
		   dp[i]=(dp[i-1]+dp[i-2])%mod;
		   return dp[n];
		}
};