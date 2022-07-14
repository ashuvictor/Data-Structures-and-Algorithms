


Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.



class Solution
{
    public:
    //Function to find the maximum number of cuts.
     int dp[100005];
     int solve(int n,int x,int y,int z)
     {
         if(n==0)
         return 0;
         int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
         if(n>=x)
         op1=solve(n-x,x,y,z);
         if(n>=y)
         op2=solve(n-y,x,y,z);
         if(n>=z)
         op3=solve(n-z,x,y,z);
         return dp[n]=1+max({op1,op2,op3});
         
     }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
       memset(dp,-1,sizeof(dp));
       int a=solve(n,x,y,z);
       if(a<0)
       return 0;
       else 
       return a;
        
    }
};



int maximizeTheCuts(int n, int x, int y, int z){
        vector <int> dp(10001);
        dp[x] = 1;
        dp[y] = 1;
        dp[z] = 1;
        for(int i=1; i<=n; i++){
            if(i-x >= 0 && dp[i-x])
                dp[i] = max(dp[i], 1+dp[i-x]);
            if(i-y >= 0 && dp[i-y])
                dp[i] = max(dp[i], 1+dp[i-y]);
            if(i-z >= 0 && dp[i-z])
                dp[i] = max(dp[i], 1+dp[i-z]);
        }
        return dp[n];
    }