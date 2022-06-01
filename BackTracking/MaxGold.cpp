In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

class Solution {
public:
    int n,m;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int solve(vector<vector<int>>&grid,int i,int j){
        
        if(i<0 or i>=m or j<0 or j>=n)
            return 0;
        if(grid[i][j]==0)
            return 0;
        int temp=grid[i][j];
        grid[i][j]=0;
        int ans=0;
        for(int k=0;k<4;k++){
            int xx=i+dx[k];
            int yy=j+dy[k];
            ans=max(ans,solve(grid,xx,yy));
        }
        grid[i][j]=temp;
        return ans+temp;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
     m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0)
                {
                    ans=max(ans,solve(grid,i,j));
                }
            }
        }
        return ans;
        
    }
};