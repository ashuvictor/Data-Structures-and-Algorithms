class Solution {

    private int fun(int[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length ||
            j < 0 || j >= grid[0].length ||
            grid[i][j] == 0) {
            return 0;
        }

        int current = grid[i][j];
        grid[i][j] = 0; // mark visited

        int best = 0;

        best = Math.max(best, fun(grid, i + 1, j)); // down
        best = Math.max(best, fun(grid, i, j - 1)); // left
        best = Math.max(best, fun(grid, i, j + 1)); // right
        best = Math.max(best, fun(grid, i - 1, j)); // up

        grid[i][j] = current; // backtrack

        return current + best;
    }

    public int getMaximumGold(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int ans = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0) {
                    ans = Math.max(ans, fun(grid, i, j));
                }
            }
        }
        return ans;
    }
}




class Solution {

    private int solve(int[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length ||
            j < 0 || j >= grid[0].length ||
            grid[i][j] == 0) {
            return 0;
        }

        int current = grid[i][j];
        grid[i][j] = 0; // mark visited

        int[][] directions = {
            {1, 0},   // down
            {0, 1},   // right
            {-1, 0},  // up
            {0, -1}   // left
        };

        int maxGold = 0;

        for (int[] d : directions) {
            maxGold = Math.max(maxGold, solve(grid, i + d[0], j + d[1]));
        }

        grid[i][j] = current; // backtrack
        return current + maxGold;
    }

    public int getMaximumGold(int[][] grid) {
        int ans = 0;
        int row = grid.length, col = grid[0].length;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0) {
                    ans = Math.max(ans, solve(grid, i, j));
                }
            }
        }
        return ans;
    }
}
