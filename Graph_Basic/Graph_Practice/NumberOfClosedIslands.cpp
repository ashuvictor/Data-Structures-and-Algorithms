Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,bool &flag){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==2 or grid[i][j]==1)
            return;
        grid[i][j]=2;
        if(i==0 or i==grid.size()-1 or j==0 or j==grid[0].size()-1)
            flag=false;
        dfs(grid,i+1,j,flag);
        dfs(grid,i,j-1,flag);
        dfs(grid,i,j+1,flag);
        dfs(grid,i-1,j,flag);
    }
    int closedIsland(vector<vector<int>>& grid) {
     int ans=0;   
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                {   bool flag=true;
                    dfs(grid,i,j,flag);
                 if(flag)
                    ans++;
                }
            }
        }
        return ans;
    }
};