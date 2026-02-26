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
class Solution {

    private boolean[][] vis;

    private boolean isValid(int x, int y, int row, int col, int[][] grid) {
        return !(x < 0 || x >= row || y < 0 || y >= col || vis[x][y] || grid[x][y] == 0);
    }

    private void dfs(int x, int y, int row, int col, int[][] grid, int[] cnt) {
        vis[x][y] = true;
        cnt[0]++;

        int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, row, col, grid)) {
                dfs(nx, ny, row, col, grid, cnt);
            }
        }
    }

    public int findMaxArea(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;

        vis = new boolean[row][col];
        int maxArea = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int[] cnt = new int[1]; // simulate pass-by-reference
                    dfs(i, j, row, col, grid, cnt);
                    maxArea = Math.max(maxArea, cnt[0]);
                }
            }
        }

        return maxArea;
    }
}



import java.util.*;

class Solution {

    private boolean isValid(int x, int y, int row, int col,
                            int[][] grid, boolean[][] vis) {
        return x >= 0 && x < row &&
               y >= 0 && y < col &&
               !vis[x][y] &&
               grid[x][y] == 1;
    }

    private void bfs(int x, int y, int row, int col,
                     int[][] grid, boolean[][] vis, int[] cnt) {

        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        vis[x][y] = true;
        cnt[0]++;

        int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int cx = curr[0];
            int cy = curr[1];

            for (int i = 0; i < 8; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (isValid(nx, ny, row, col, grid, vis)) {
                    q.offer(new int[]{nx, ny});
                    vis[nx][ny] = true;
                    cnt[0]++;
                }
            }
        }
    }

    public int findMaxArea(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int maxArea = 0;

        boolean[][] vis = new boolean[row][col];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int[] cnt = new int[1]; // simulate reference
                    bfs(i, j, row, col, grid, vis, cnt);
                    maxArea = Math.max(maxArea, cnt[0]);
                }
            }
        }

        return maxArea;
    }
}