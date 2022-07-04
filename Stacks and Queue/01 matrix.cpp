


Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.


class Solution {
public:
    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dis(m, vector<int> (n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for (int dir = 0; dir < 4; ++dir) {
                int ii = i + di[dir];
                int jj = j + dj[dir];
                if (ii >= 0 and ii < m and jj >= 0 and jj < n and dis[ii][jj] == -1) {
                    dis[ii][jj] = dis[i][j] + 1;
                    q.push({ii, jj});
                }
            }
        }
        
        return dis;
    }
};



class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int r, int c)
    {
        if(r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size() || matrix[r][c] == -1)
            return 10000;
        
        if(matrix[r][c] == 0 || matrix[r][c] == 1)
            return matrix[r][c];
        
        int temp = matrix[r][c];
        
        matrix[r][c] = -1;
        
        int left = 1+dfs(matrix, r, c-1);
        int right = 1+dfs(matrix, r, c+1);
        int down = 1+dfs(matrix, r-1, c);
        int up = 1+dfs(matrix, r+1, c);
        
        matrix[r][c] = min({temp, left, right, down, up});
        return matrix[r][c];
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j])
                    matrix[i][j] = 10000;
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j])
                    dfs(matrix, i, j);
        return matrix;
        
    }
};