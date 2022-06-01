

class Solution {
public:

    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n,int &cnt){
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]==2 or grid[i][j]==0)
            return;
        grid[i][j]=2;
      cnt++;
        dfs(grid,i+1,j,m,n,cnt);
        dfs(grid,i,j-1,m,n,cnt);
        dfs(grid,i,j+1,m,n,cnt);
        dfs(grid,i-1,j,m,n,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    int cnt=0;
                    dfs(grid,i,j,m,n,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int cnt;
    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n){
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]==2 or grid[i][j]==0)
            return;
        
        
        cnt++;
        grid[i][j]=2;
        dfs(grid,i+1,j,m,n);
        dfs(grid,i,j-1,m,n);
        dfs(grid,i,j+1,m,n);
        dfs(grid,i-1,j,m,n);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    cnt=0;
                    dfs(grid,i,j,m,n);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};