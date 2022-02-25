class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       
       int n = grid.size();
       int m = grid[0].size();
       int freshOranges = 0;
       queue<pair<int, int>> q;
       
       for(int i=0; i<n; i++) {
           for(int j=0; j<m; j++) {
               
               if(grid[i][j] == 2) {
                   q.push({i, j});
               } else if(grid[i][j] == 1) {
                   freshOranges++;
               }
           }
       }
        if(freshOranges==0)
            return 0;
       
       int cnt = 0;
       int dx[4] = {-1, 0, 1, 0};
       int dy[4] = {0, 1, 0, -1};
       int orangesRotten = 0;
       
       while(!q.empty()) {
           
           int qsz = q.size();
           
           while(qsz--) {
               
               int x = q.front().first;
               int y = q.front().second;
               q.pop();
               
               for(int i=0; i<4; i++) {
                   
                   int nx = x + dx[i];
                   int ny = y + dy[i];
                   
                   if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                       
                       grid[nx][ny] = 2;
                       q.push({nx, ny});
                       orangesRotten++;
                   }
               }
           }
           
           cnt++;
           
           if(orangesRotten == freshOranges) {
               return cnt;
           }
       }
       
       return -1;
   } 
};