You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

You may change 0's to 1's to connect the two islands to form one island.

Return the smallest number of 0's you must flip to connect the two islands.

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Brute force
class Solution {
public:
    void flood_fill(vector<vector<int>>&grid,int i,int j,vector<pair<int,int>>&r)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid.size() or grid[i][j]==0)
            return;
        grid[i][j]=0;
        r.push_back({i,j});
        flood_fill(grid,i+1,j,r);
          flood_fill(grid,i,j-1,r);
          flood_fill(grid,i,j+1,r);
          flood_fill(grid,i-1,j,r);
    }
    int shortestBridge(vector<vector<int>>& grid) {
      vector<pair<int,int>>x;
        vector<pair<int,int>>y;int count=0;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    count++;
                    if(count==1)
                    {
                        flood_fill(grid,i,j,x);
                    }
                    if(count==2)
                    {
                        flood_fill(grid,i,j,y);
                    }
                }
            }
            if(count==2)
                break;
        }
        int min_dist=INT_MAX;
        for(int i=0;i<x.size();i++){
            for(int j=0;j<y.size();j++){
                int dist=abs(x[i].first-y[j].first)+abs(x[i].second-y[j].second)-1;
                if(dist<min_dist)
                    min_dist=dist;
            }
        }
    return min_dist;}
};

optimal but tle
class Solution {
public:
    void dfs(vector<vector<int>>&grid,int i,int j,queue<pair<int,int>>&q,set<pair<int,int>>&visited)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid.size() or grid[i][j]==0 or visited.find({i,j})!=visited.end())
            return;
        q.push({i,j});
        visited.insert({i,j});
        dfs(grid,i+1,j,q,visited);
        dfs(grid,i,j-1,q,visited);
        dfs(grid,i,j+1,q,visited);
        dfs(grid,i-1,j,q,visited);
            
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
       set<pair<int,int>>visited;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j,q,visited);
                     i=grid.size();
                    break;
                }
            }
        }
        int count=0;
        int dx[4]={1,0,0,-1};
        int dy[4]={0,-1,1,0};
        
        while(!q.empty())
        {
            int len=q.size();
            while(len--){
                int x1=q.front().first;
                int y1=q.front().second;
               
                for(int i=0;i<4;i++)
                {
                    int tempx=x1+dx[i];
                    int tempy=y1+dy[i];
                    if(tempx>=0 and tempx<n and tempy>=0 and tempy<n and visited.find({tempx,tempy})==visited.end())
                        if(grid[tempx][tempy]==1)
                            return count;
                    q.push({tempx,tempy});
                    visited.insert({tempx,tempy});
                }
                q.pop();
            }
             
            count++;
        }
        return -1;
    }
};

best
class Solution
{
public:
    
     queue<pair<int, int>> q;
    
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {

        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0 || grid[i][j] == -1)
            return false;

        else
            return true;
    }

    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (isValid(i, j, grid) == false)
            return;

        q.push({i,j});
        
        grid[i][j] = -1;

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

    int shortestBridge(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        bool breaked = false ;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                    breaked = true;
                        break;
                }
             
            }
               if(breaked)
                    break;
        }

      
       
        int steps = 0;
       


        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                auto top = q.front();
                q.pop();

                int x = top.first;
                int y = top.second;

                for (int k = 0; k < 4; k++)
                {
                    int newX = x + dx[k];
                    int newY = y + dy[k];

                    if (newX < 0 || newY < 0 || newX == m || newY == n || grid[newX][newY] == -1)
                    {
                        continue;
                    }

                    if (grid[newX][newY] == 1)
                        return steps ; 

                    grid[newX][newY] = -1;

                    q.push({newX, newY});
                }
            }
            steps++;
        }
        return -1; 
    }
};