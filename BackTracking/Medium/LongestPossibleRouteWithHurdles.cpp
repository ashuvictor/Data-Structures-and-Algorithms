Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the length of the longest possible route possible 
from source to a destination within the matrix. We are allowed to move to only adjacent cells which are not hurdles.
 The route cannot contain any diagonal moves and a location once visited in a particular path cannot be visited again.
 https://www.youtube.com/watch?v=1iYB8h6W-Xs&list=PLlGpFGXC9XnYAL7SnEfyDwycO-9KIk_oq&index=7

import java.util.*;

public class Main {

    static void solve(int r, int c, int[][] mat, boolean[][] visited,
                      int[] ans, int prow, int pcol, int dx, int dy, int pathLength) {

        // reached destination
        if (prow == dx && pcol == dy) {
            ans[0] = Math.max(ans[0], pathLength);
            return;
        }

        // boundary + invalid conditions
        if (prow < 0 || pcol < 0 || prow >= r || pcol >= c ||
            visited[prow][pcol] || mat[prow][pcol] == 0)
            return;

        visited[prow][pcol] = true;

        // right
        solve(r, c, mat, visited, ans, prow, pcol + 1, dx, dy, pathLength + 1);
        // left
        solve(r, c, mat, visited, ans, prow, pcol - 1, dx, dy, pathLength + 1);
        // up
        solve(r, c, mat, visited, ans, prow - 1, pcol, dx, dy, pathLength + 1);
        // down
        solve(r, c, mat, visited, ans, prow + 1, pcol, dx, dy, pathLength + 1);

        visited[prow][pcol] = false; // backtrack
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int r = sc.nextInt();
        int c = sc.nextInt();

        int[][] mat = new int[r][c];

        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                mat[i][j] = sc.nextInt();

        int x1 = sc.nextInt(); // source
        int y1 = sc.nextInt();
        int x2 = sc.nextInt(); // destination
        int y2 = sc.nextInt();

        boolean[][] visited = new boolean[r][c];

        int[] ans = {Integer.MIN_VALUE};

        if (mat[x1][y1] == 0) {
            System.out.println("source point is a hurdle");
        } else {
            solve(r, c, mat, visited, ans, x1, y1, x2, y2, 0);
            System.out.println("Maximum distance from source to destination is");
            System.out.println(ans[0]);
        }
    }
}