You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.



https://leetcode.com/problems/count-sub-islands/
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid1,vector<vector<int>>&grid2,bool &flag)
    {
        if(i<0 or i>=grid2.size() or j<0 or j>=grid2[0].size() or grid2[i][j]==2 or grid2[i][j]==0)
        {
            return;
        }
        if(grid1[i][j]==0)
        {
            flag=false;return;
        }
        grid2[i][j]=0;
        dfs(i+1,j,grid1,grid2,flag);
          dfs(i,j-1,grid1,grid2,flag);
          dfs(i,j+1,grid1,grid2,flag);
          dfs(i-1,j,grid1,grid2,flag);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        int m=grid2.size();
        int n=grid2[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1)
                {
                    bool flag=true;
                    dfs(i,j,grid1,grid2,flag);
                    if(flag)
                        ans++;
                }
            }
        }
        return ans;
    }
};