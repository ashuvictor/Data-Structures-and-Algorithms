



class Solution{
public:
   int maxSquare(int n, int m, vector<vector<int>> mat)
   {
       // code here
       int dp[n][m];
       int ans=0;
       for(int i=0;i<n;i++)
       {
           dp[i][0] = mat[i][0];
           if(mat[i][0]==1){
               ans = 1;
           }
       }
       for(int i=0;i<m;i++){
           dp[0][i] = mat[0][i];
           if(mat[0][i]==1){
               ans=1;
           }
       }
       for(int i=1;i<n;i++)
       {
           for(int j=1;j<m;j++)
           {
               if(mat[i][j]==0){
                   dp[i][j] = 0;
               }
               else
               {
                   dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
               }
               ans = max(ans,dp[i][j]);
           }
       }
       return ans;
   }
};