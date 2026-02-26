import java.util.*;

public class Main {

    static void solve(int n, int i, int j, int cnt,
                      int[][] mat, boolean[][] visited) {

        // out of bounds
        if (i < 0 || j < 0 || i >= n || j >= n)
            return;

        // already visited
        if (visited[i][j])
            return;

        // last move
        if (cnt == (n * n - 1)) {
            mat[i][j] = cnt;
            return;
        }

        visited[i][j] = true;
        mat[i][j] = cnt;

        // 8 knight moves
        solve(n, i - 1, j + 2, cnt + 1, mat, visited);
        solve(n, i - 1, j - 2, cnt + 1, mat, visited);
        solve(n, i + 1, j + 2, cnt + 1, mat, visited);
        solve(n, i + 1, j - 2, cnt + 1, mat, visited);
        solve(n, i - 2, j + 1, cnt + 1, mat, visited);
        solve(n, i - 2, j - 1, cnt + 1, mat, visited);
        solve(n, i + 2, j + 1, cnt + 1, mat, visited);
        solve(n, i + 2, j - 1, cnt + 1, mat, visited);

        visited[i][j] = false; // backtrack
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[][] mat = new int[n][n];
        boolean[][] visited = new boolean[n][n];

        solve(n, 0, 0, 0, mat, visited);

        // print board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(mat[i][j] + " ");
            }
            System.out.println();
        }
    }
}