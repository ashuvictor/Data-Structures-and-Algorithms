You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0,rotten=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                {
                q.push({i,j});
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0)
            return 0;
      
        int ans=0;
        while(!q.empty()){
            int qsz=q.size();
            while(qsz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        rotten++;
                    }
                }
            }
            ans++;
             if(fresh==rotten)
            return ans;
        }
       
        return -1;
    }
};