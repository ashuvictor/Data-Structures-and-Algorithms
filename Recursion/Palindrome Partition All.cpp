


132. Palindrome Partitioning II

class Solution {
public:
	vector<int> dp;
	int isPali(string &s,int l,int r){
		while(l<r){
			if(s[l++]!=s[r--]) return false;
		}
		return true;
	}
	int solve(string &s,int pos,int n){
		if(pos>=n  || isPali(s,pos,n)) return 0;
		if(dp[pos]!=-1) return dp[pos];
		int ans=0,tmp=INT_MAX;
		for(int i=pos;i<n;i++){
			if(isPali(s,pos,i)){
				ans=1+solve(s,i+1,n);
				tmp=min(tmp,ans);
			}
		}
		return dp[pos] = tmp;
	}
	int minCut(string s) {
		dp.assign(s.size(),-1);
		return solve(s,0,s.size())-1;
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