class Solution {

    public void solveSudoku(char[][] board) {
        solve(board);
    }

    private boolean solve(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {

                if (board[i][j] == '.') {

                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.'; // backtrack
                        }
                    }

                    return false; // no number fits
                }
            }
        }
        return true; // solved
    }

    private boolean isValid(char[][] board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {

            // column check
            if (board[i][col] == c) return false;

            // row check
            if (board[row][i] == c) return false;

            // 3x3 subgrid check
            int r = 3 * (row / 3) + i / 3;
            int cl = 3 * (col / 3) + i % 3;
            if (board[r][cl] == c) return false;
        }
        return true;
    }
}