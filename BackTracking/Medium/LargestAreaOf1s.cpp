Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored
in orange.

https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/?page=1&difficulty[]=1&status[]=solved&category[]=Graph&sortBy=submissions
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    bool vis[1001][1001];
   
   bool isvalid(int x,int y,int row,int col,vector<vector<int>> &grid)
   {
       if(x<0 || x>=row || y<0 || y>=col ||vis[x][y]==true || grid[x][y]==0)
           return false;
      
       return true;
   }
   void dfs(int x,int y,int row,int col,vector<vector<int>> &grid,int &cnt)
   {
       vis[x][y]=true;
       cnt++;
       int dx[]={-1,-1,-1,0,0,1,1,1};
       int dy[]={-1,0,1,-1,1,-1,0,1};
       for(int i=0;i<8;i++)
       {
           if(isvalid(x+dx[i],y+dy[i],row,col,grid))
           {
               dfs(x+dx[i],y+dy[i],row,col,grid,cnt);
           }
       }
       
   }
    int findMaxArea(vector<vector<int>>& grid) {
        int row=grid.size();
       int col=grid[0].size();
       int len=0;
       for(int i=0;i<row;i++)
       {
           for(int j=0;j<col;j++)
           {
               vis[i][j]=false;
           }
       }
       for(int i=0;i<row;i++)
       {
           for(int j=0;j<col;j++)
           {
               if(grid[i][j]==1&& vis[i][j]==false)
               {
                   int cnt=0;
                   dfs(i,j,row,col,grid,cnt);
                   len=max(cnt,len);
               }
               
           }
       }
       return len;
    }
};




#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find unit area of the largest region of 1s using BFS
    bool isvalid(int x, int y, int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        return (x >= 0 && x < row && y >= 0 && y < col && !vis[x][y] && grid[x][y] == 1);
    }
    
    void bfs(int x, int y, int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis, int &cnt) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = true;
        cnt++;
        
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            
            for (int i = 0; i < 8; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if (isvalid(nx, ny, row, col, grid, vis)) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                    cnt++;
                }
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int len = 0;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int cnt = 0;
                    bfs(i, j, row, col, grid, vis, cnt);
                    len = max(cnt, len);
                }
            }
        }
        return len;
    }
};
