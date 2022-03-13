Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

Example:
Input
3
8
20
13
Output
1
4
2
Explanation
For 1st example when n = 8
{ 3, 5 } and {5, 3} are the 
two possible permutations but 
these represent the same 
cobmination. Hence output is 1.

https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
long long recursion(int i,long long sum,int *a)

{

    if(sum==0)  return 1;

    if(i==3 || sum<0) return 0;

    if(dp[i][sum]!=-1)  return dp[i][sum];

    long long ans1= recursion(i,sum-a[i],a);

    long long ans2= recursion(i+1,sum,a);

    return dp[i][sum]=(ans1+ans2);

}

long long int count(long long int n)

{

    for(int i=0;i<3;i++)

        for(int j=0;j<1001;j++) 

            dp[i][j]=-1;

int a[3]={3,5,10};

return recursion(0,n,a);

}

long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	
	// Your code here
	int S[3]={3,5,10};
	for(int i=0;i<3;i++){
	    for(int j=S[i];j<=n;j++){
	        table[j]+=table[j-S[i]];
	    }
	}
	
	return table[n];
}


