
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
int maxChainLen(struct val p[],int n)
{
//Your code here
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
    v.push_back({p[i].first,p[i].second});
}
sort(v.begin(),v.end());
vector<int>dp(n,1);
for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(v[j].second<v[i].first)
        dp[i]=max(dp[i],dp[j]+1);
    }
}
int ma=0;
for(int i=0;i<n;i++)
ma=max(ma,dp[i]);
return ma;

}