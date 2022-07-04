
https://leetcode.com/problems/island-perimeter/
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example 1:


Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

class Solution {
public:
  
    void dfs(vector<vector<int>>&grid,int i,int j,int m,int n,int &ans)
    {
        if(i<0 or i>=m or j<0 or j>=n or  grid[i][j]==0)
        {ans++;
            
            return;}
        if(grid[i][j]==2)
            return;
        grid[i][j]=2;
      
        dfs(grid,i+1,j,m,n,ans);
        dfs(grid,i,j+1,m,n,ans);
        dfs(grid,i,j-1,m,n,ans);
        dfs(grid,i-1,j,m,n,ans);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,m,n,ans);
                    return ans;
                }
            }
        }
        return 0;
    }
};


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    ans+=4;
                
                if(i>0 and grid[i-1][j]==1)
                    ans-=2;
                if(j>0 and grid[i][j-1]==1)
                    ans-=2;
            }
            }
        }
        return ans;
    }
};