


Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.


import java.util.*;

class Solution {

    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        int[][] dis = new int[m][n];
        Queue<int[]> q = new ArrayDeque<>();

        int[] di = {1, 0, -1, 0};
        int[] dj = {0, 1, 0, -1};

        // initialize distances
        for (int i = 0; i < m; i++) {
            Arrays.fill(dis[i], -1);
        }

        // push all zeros (multi-source BFS)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dis[i][j] = 0;
                    q.offer(new int[]{i, j});
                }
            }
        }

        // BFS
        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int i = cell[0], j = cell[1];

            for (int dir = 0; dir < 4; dir++) {
                int ii = i + di[dir];
                int jj = j + dj[dir];

                if (ii >= 0 && ii < m && jj >= 0 && jj < n && dis[ii][jj] == -1) {
                    dis[ii][jj] = dis[i][j] + 1;
                    q.offer(new int[]{ii, jj});
                }
            }
        }

        return dis;
    }
}






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