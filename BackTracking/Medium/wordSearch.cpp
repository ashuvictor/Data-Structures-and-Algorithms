class Solution {

    private boolean fun(char[][] board, String word, int i, int j, int idx) {
        if (idx == word.length())
            return true;

        if (i < 0 || i >= board.length ||
            j < 0 || j >= board[0].length ||
            board[i][j] != word.charAt(idx))
            return false;

        char temp = board[i][j];
        board[i][j] = '$'; // mark visited

        boolean found =
                fun(board, word, i, j + 1, idx + 1) ||
                fun(board, word, i, j - 1, idx + 1) ||
                fun(board, word, i - 1, j, idx + 1) ||
                fun(board, word, i + 1, j, idx + 1);

        board[i][j] = temp; // restore
        return found;
    }

    public boolean exist(char[][] board, String word) {
        int rows = board.length, cols = board[0].length;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word.charAt(0)) {
                    if (fun(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
}