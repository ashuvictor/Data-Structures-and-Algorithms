Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.
 

Example 1:

Input: board = {{a,g,b,c},{q,e,e,l},{g,b,k,s}},
word = "geeks"
Output: 1
Explanation: The board is-
a g b c
q e e l
g b k s
The letters which are used to make the
"geeks" are colored.
https://practice.geeksforgeeks.org/problems/word-search/1/?page=1&difficulty[]=1&status[]=solved&category[]=Graph&sortBy=submissions
class Solution {

    private boolean solve(char[][] board, String word, int i, int j) {
        if (word.length() == 0)
            return true;

        if (i < 0 || i >= board.length ||
            j < 0 || j >= board[0].length ||
            board[i][j] != word.charAt(0))
            return false;

        char c = board[i][j];
        board[i][j] = '*'; // mark visited

        String subs = word.substring(1);

        boolean found =
                solve(board, subs, i - 1, j) ||
                solve(board, subs, i, j + 1) ||
                solve(board, subs, i + 1, j) ||
                solve(board, subs, i, j - 1);

        board[i][j] = c; // restore
        return found;
    }

    public boolean isWordExist(char[][] board, String word) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (solve(board, word, i, j))
                    return true;
            }
        }
        return false;
    }
}

class Solution {

    private boolean solve(char[][] mat, String word, int i, int j, int index) {
        // base case
        if (index == word.length()) return true;

        // boundary + mismatch
        if (i < 0 || i >= mat.length ||
            j < 0 || j >= mat[0].length ||
            mat[i][j] != word.charAt(index)) {
            return false;
        }

        // mark visited
        char temp = mat[i][j];
        mat[i][j] = '*';

        boolean found =
                solve(mat, word, i + 1, j, index + 1) ||
                solve(mat, word, i - 1, j, index + 1) ||
                solve(mat, word, i, j + 1, index + 1) ||
                solve(mat, word, i, j - 1, index + 1);

        // backtrack
        mat[i][j] = temp;
        return found;
    }

    public boolean isWordExist(char[][] mat, String word) {
        int rows = mat.length, cols = mat[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (solve(mat, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
}
