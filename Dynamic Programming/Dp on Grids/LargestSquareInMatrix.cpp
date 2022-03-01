/*
Given a binary matrix mat of size n * m, find out the maximum size square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.
*/
class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int dp[n][m];int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 and j==m-1)
                dp[i][j]=mat[i][j];
                else if(i==n-1 or j==m-1)
                dp[i][j]=mat[i][j];
                else
                {
                    if(mat[i][j]==0)
                    dp[i][j]=0;
                    else
                    dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
                }
            
            if(dp[i][j]>ans)
            ans=dp[i][j];}
        }
        return ans;
    }
};
