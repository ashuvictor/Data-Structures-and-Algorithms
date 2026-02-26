Print all possible paths from top left to bottom right of a mXn matrix
Difficulty Level : Medium
Last Updated : 25 Jan, 2022
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Examples : 

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4

import java.util.*;

public class Main {

    static void findPaths(int x, int y, int rows, int cols,
                          int[][] mat, boolean[][] visited,
                          List<Integer> path,
                          List<List<Integer>> allPaths) {

        // reached destination
        if (x == rows - 1 && y == cols - 1) {
            path.add(mat[x][y]);
            allPaths.add(new ArrayList<>(path));
            path.remove(path.size() - 1); // backtrack
            return;
        }

        // invalid
        if (x < 0 || x >= rows || y < 0 || y >= cols || visited[x][y])
            return;

        path.add(mat[x][y]);
        visited[x][y] = true;

        // right
        findPaths(x, y + 1, rows, cols, mat, visited, path, allPaths);
        // down
        findPaths(x + 1, y, rows, cols, mat, visited, path, allPaths);

        visited[x][y] = false;
        path.remove(path.size() - 1); // backtrack
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int rows = sc.nextInt();
        int cols = sc.nextInt();

        int[][] mat = new int[rows][cols];
        boolean[][] visited = new boolean[rows][cols];

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                mat[i][j] = sc.nextInt();

        List<Integer> path = new ArrayList<>();
        List<List<Integer>> allPaths = new ArrayList<>();

        findPaths(0, 0, rows, cols, mat, visited, path, allPaths);

        System.out.println(allPaths.size());

        for (List<Integer> p : allPaths) {
            for (int val : p) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}