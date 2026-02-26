Given a path in the form of a rectangular matrix having few landmines arbitrarily placed (marked as 0), 
calculate length of the shortest safe route possible from any cell in the first column to any cell in the last column of the matrix.
 We have to avoid landmines and their four adjacent cells (left, right, above and below) as they are also unsafe. 
We are allowed to move to only adjacent cells which are not landmines. i.e. the route cannot contains any diagonal moves.
https://www.youtube.com/watch?v=yRjTasFWB9E
import java.util.*;

public class Main {

    static int solve(int row, int col, Set<String> blocked,
                     boolean[][] visited, int i, int j, int cnt) {

        if (i == row || i < 0 || j < 0 || j == col ||
            blocked.contains(i + "," + j) || visited[i][j])
            return Integer.MAX_VALUE;

        if (j == col - 1)
            return cnt;

        visited[i][j] = true;

        int l1 = solve(row, col, blocked, visited, i + 1, j, cnt + 1);
        int l2 = solve(row, col, blocked, visited, i - 1, j, cnt + 1);
        int l3 = solve(row, col, blocked, visited, i, j + 1, cnt + 1);
        int l4 = solve(row, col, blocked, visited, i, j - 1, cnt + 1);

        visited[i][j] = false;

        return Math.min(Math.min(l1, l2), Math.min(l3, l4));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int row = sc.nextInt();
        int col = sc.nextInt();

        int[][] mat = new int[row][col];
        boolean[][] visited = new boolean[row][col];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                mat[i][j] = sc.nextInt();

        // Blocked cells (0 + neighbors)
        Set<String> blocked = new HashSet<>();

        int[][] dir = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0) {
                    for (int[] d : dir) {
                        int ni = i + d[0];
                        int nj = j + d[1];
                        if (ni >= 0 && ni < row && nj >= 0 && nj < col)
                            blocked.add(ni + "," + nj);
                    }
                }
            }
        }

        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < row; i++) {
            if (!blocked.contains(i + ",0")) {
                int length = solve(row, col, blocked, visited, i, 0, 0);
                System.out.println(i + " " + length);
                ans = Math.min(ans, length);
            }
        }

        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
    }
}