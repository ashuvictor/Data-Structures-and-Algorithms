iven a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}

https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1/?page=1&difficulty[]=1&status[]=solved&category[]=Graph&sortBy=submissions






import java.util.*;

class Solution {

    private void helper(char[][] mat, int i, int j) {
        if (i < 0 || j < 0 || i >= mat.length || j >= mat[0].length || mat[i][j] != 'O')
            return;

        mat[i][j] = '#';

        helper(mat, i - 1, j);
        helper(mat, i + 1, j);
        helper(mat, i, j - 1);
        helper(mat, i, j + 1);
    }

    public char[][] fill(int n, int m, char[][] mat) {
        n = mat.length;
        m = mat[0].length;

        // Top boundary
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 'O') helper(mat, 0, j);
        }

        // Right boundary
        for (int i = 0; i < n; i++) {
            if (mat[i][m - 1] == 'O') helper(mat, i, m - 1);
        }

        // Bottom boundary
        for (int j = m - 1; j >= 0; j--) {
            if (mat[n - 1][j] == 'O') helper(mat, n - 1, j);
        }

        // Left boundary
        for (int i = n - 1; i >= 0; i--) {
            if (mat[i][0] == 'O') helper(mat, i, 0);
        }

        // Convert remaining O → X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }

        // Restore boundary-connected cells (# → O)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '#')
                    mat[i][j] = 'O';
            }
        }

        return mat;
    }
}