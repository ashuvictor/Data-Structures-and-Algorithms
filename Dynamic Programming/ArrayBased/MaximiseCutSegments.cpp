class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10005];
    int helper(int n,int x,int y,int z){
        if(n==0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
        if(n>=x)
       op1= helper(n-x,x,y,z);
        if(n>=y)
        op2=helper(n-y,x,y,z);
        if(n>=z)
        op3=helper(n-z,x,y,z);
        return dp[n]=1+max(op1,max(op2,op3));
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {memset(dp,-1,sizeof(dp));
    int a =helper(n,x,y,z);
    if(a<0)
    return 0;
    return a;
        
    }
};