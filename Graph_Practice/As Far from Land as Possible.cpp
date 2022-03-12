Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

 

Example 1:


Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
multi source bfs we put all the ones then one by one distance we cover the levels and get the maximum
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       int n=grid.size();
        queue<pair<int,int>>q;
        bool ones=false,zero=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    ones=true;q.push({i,j});
                }
                else
                    zero=true;
            }
        }
        if(ones==false or zero==false)
            return -1;
        else{
            int dx[4]={1,0,0,-1};
            int dy[4]={0,-1,1,0};
            int ans=0;int depth=0;
            while(!q.empty())
            {
                int sz=q.size();
                 ans=max(ans,depth);depth++;
                for(int i=0;i<sz;i++){
                    int x=q.front().first;
                    int y=q.front().second;q.pop();
                    for(int i=0;i<4;i++){
                        int x1=x+dx[i];
                        int y1=y+dy[i];
                        if(x1>=0 and x1<n and y1>=0 and y1<n and grid[x1][y1]==0)
                        {
                            q.push({x1,y1});
                            grid[x1][y1]=1;
                        }
                    }
                   
                }
            }
            return ans;
        }
            
    }
};