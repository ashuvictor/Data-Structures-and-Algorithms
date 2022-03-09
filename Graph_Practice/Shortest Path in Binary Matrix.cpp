Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.


int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> q;
        
		//if 1st element (0,0) is 0 then only push into queue, else return -1.
        if(grid[0][0] == 0)
            q.push({0,0});
        
		//mark it visited
        grid[0][0] = 1;
        
        int shortestDist=0;
        while(!q.empty())
        {
            shortestDist++;
            int size = q.size();
            
            while(size-- > 0)
            {
                pair<int,int> p = q.front();
                int x = p.first;
                int y = p.second;

                q.pop();

                //reached the destination
                if(x==row-1 && y==col-1)
                {
                    return shortestDist;
                }

               
                int dx[]={-1,0,1,0,1,1,-1,-1};
                int dy[]={0,-1,0,1,1,-1,1,-1};

				//check in all 8-directions
                for(int i=0;i<8;i++)
                {
                    int a = x + dx[i];
                    int b = y + dy[i];

                    if(a>=0 && a<row && b>=0 && b<col && grid[a][b]==0)
                    {
						//push it into queue
                        q.push({a,b});
						
						//mark it visited
                        grid[a][b] = 1;
                    }
                }
            }
        }
        return -1;
    }

class Solution {
public://dlru  
 //vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
    int dx[8]={1,-1,0,0,-1,1,1,-1};
    int dy[8]={0,0,1,-1,1,1,-1,-1};
    void bfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dist){
        queue<pair<int,int>>q;int n=grid.size();
        dist[0][0]=0;
        q.push({i,j});
        grid[i][j]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;q.pop();
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 and nx<n and ny>=0 and ny<n and grid[nx][ny]==0)
                {
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                    dist[nx][ny]=dist[x][y]+1;
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                {
                    bfs(grid,i,j,dist);
                }
            }
        }
        int ans=dist[n-1][n-1];
        if(ans>=1e9)
            return -1;
        return ans+1;
    }
};