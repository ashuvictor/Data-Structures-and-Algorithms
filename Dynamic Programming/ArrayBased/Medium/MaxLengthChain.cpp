

You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. 
 

Example 1:

Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3
Explanation: The given pairs are { {5, 24}, {39, 60},
{15, 28}, {27, 40}, {50, 90} },the longest chain that
can be formed is of length 3, and the chain is
{{5, 24}, {27, 40}, {50, 90}}


https://practice.geeksforgeeks.org/problems/max-length-chain/1
int maxChainLen(struct val p[],int n)
{
int dp[n];
vector<pair<int,int>>pa;
for(int i=0;i<n;i++)
pa.push_back({p[i].first,p[i].second});
sort(pa.begin(),pa.end());
for(int i=0;i<n;i++)
dp[i]=1;
for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(pa[j].second<pa[i].first){
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
}
int ans=0;
for(int i=0;i<n;i++){
    ans=max(dp[i],ans);
}
return ans;}