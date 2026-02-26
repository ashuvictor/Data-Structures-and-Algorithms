Rat in a Maze
import java.util.*;

class Solution {

    private void solve(List<String> ans, int[][] m, int n,
                       int i, int j, StringBuilder path) {

        // invalid cell
        if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] != 1)
            return;

        // destination reached
        if (i == n - 1 && j == n - 1) {
            ans.add(path.toString());
            return;
        }

        m[i][j] = -1; // mark visited

        // Down
        path.append('D');
        solve(ans, m, n, i + 1, j, path);
        path.deleteCharAt(path.length() - 1);

        // Left
        path.append('L');
        solve(ans, m, n, i, j - 1, path);
        path.deleteCharAt(path.length() - 1);

        // Right
        path.append('R');
        solve(ans, m, n, i, j + 1, path);
        path.deleteCharAt(path.length() - 1);

        // Up
        path.append('U');
        solve(ans, m, n, i - 1, j, path);
        path.deleteCharAt(path.length() - 1);

        m[i][j] = 1; // backtrack
    }

    public List<String> findPath(int[][] m, int n) {
        List<String> ans = new ArrayList<>();

        if (m[0][0] == 0) return ans; // no path if start blocked

        solve(ans, m, n, 0, 0, new StringBuilder());
        Collections.sort(ans); // GFG requires sorted output
        return ans;
    }
}

methods2
import java.util.*;

class Solution {

    private void solve(int i, int j, int[][] grid, int n,
                       List<String> ans, StringBuilder move,
                       boolean[][] vis, int[] dx, int[] dy) {

        if (i == n - 1 && j == n - 1) {
            ans.add(move.toString());
            return;
        }

        String dir = "DLRU";

        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + dx[ind];
            int nextj = j + dy[ind];

            if (nexti >= 0 && nextj >= 0 &&
                nexti < n && nextj < n &&
                !vis[nexti][nextj] && grid[nexti][nextj] == 1) {

                vis[i][j] = true;

                move.append(dir.charAt(ind));
                solve(nexti, nextj, grid, n, ans, move, vis, dx, dy);
                move.deleteCharAt(move.length() - 1);

                vis[i][j] = false; // backtrack
            }
        }
    }

    public List<String> findPath(int[][] m, int n) {
        List<String> ans = new ArrayList<>();

        if (m[0][0] == 0) return ans;

        boolean[][] vis = new boolean[n][n];
        int[] dx = {1, 0, 0, -1};
        int[] dy = {0, -1, 1, 0};

        solve(0, 0, m, n, ans, new StringBuilder(), vis, dx, dy);
        Collections.sort(ans); // required for GFG
        return ans;
    }
}

    