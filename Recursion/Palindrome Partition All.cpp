


132. Palindrome Partitioning II

every string can have maximum n-1 partition
class Solution {
public:
    bool isPalin(int l,int r,string s)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++,r--;
        }
        return true;
    }
    int solve(int i,int n,string &str){
        if(i==n)
            return 0;

        int minCost=INT_MAX;
        for(int j=i;j<str.size();j++){
            if(isPalin(i,j,str))
            {
                int cost=1+solve(j+1,n,str);
                minCost=min(minCost,cost);
            }
        }
        return minCost;
    }
    int minCut(string s) {
        int n=s.size();
        return solve(0,n,s)-1;
    }
};
class Solution {
public:
    bool isPalin(int l,int r,string &s)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++,r--;
        }
        return true;
    }
    int solve(int i,int n,string &str,vector<int>&dp){
        if(i>=n or isPalin(i,n,str))
            return 0;
if(dp[i]!=-1)
    return dp[i];
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalin(i,j,str))
            {
                int cost=1+solve(j+1,n,str,dp);
                minCost=min(minCost,cost);
            }
        }
        return dp[i]=minCost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(0,n,s,dp)-1;
    }
};
class Solution {
public:
    bool isPalin(int l,int r,string &s)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++,r--;
        }
        return true;
    }

    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        int mincost=INT_MAX;
       for(int i=n-1;i>=0;i--){
           for(int j=i;j<n;j++){
               if(isPalin(i,j,s))
               {
                   int cost=1+dp[j+1];
                   mincost=min(cost,mincost);
               }
           }
           dp[i]=mincost;
       }
        return dp[0];
    }
};
1278. Palindrome Partitioning III

class Solution {
public:
	vector<vector<int>> cost;
	int costFun(string &s,int l,int r){
		if(l>=r) return 0;
		if(cost[l][r]!=-1) return cost[l][r];
		return cost[l][r] = (s[l]!=s[r]) + costFun(s,l+1,r-1);
	}

	vector<vector<int>>dp;
	int solve(string &s,int k,int pos,int n){
		if(k==0) return costFun(s,pos,n-1);
		if(pos>=n) return INT_MAX;
		if(dp[pos][k]!=-1) return dp[pos][k];
		int ans=1e6;
		for(int i=pos;i<n-1;i++){
			ans=min(ans,costFun(s,pos,i)+solve(s,k-1,i+1,n));
		}
		return dp[pos][k] = ans;
	}
	int palindromePartition(string s, int k) {
		int n=s.size();
		cost.assign(n,vector<int>(n,-1));
		dp.assign(n,vector<int>(k+1,-1));
		return solve(s,k-1,0,n);
	}
};


1745. Palindrome Partitioning IV

class Solution {
public:
	vector<int> dp;
	vector<vector<int>> pali;
	int isPali(string &s,int l,int r){
		if(l>=r) return 1;
		if(pali[l][r]!=-1) return pali[l][r];
		if(s[l]==s[r]) return pali[l][r] = isPali(s,l+1,r-1);
		return pali[l][r] = 0;
	}

	bool checkPartitioning(string s) {
		int n=s.size();
		pali.assign(n,vector<int>(n,-1));
		for(int i=1;i<n-1;i++){
			for(int j=1;j<=i;j++){
				if(isPali(s,0,j-1) && isPali(s,j,i) && isPali(s,i+1,n-1)) return true;
			}
		}
		return false;
	}
};