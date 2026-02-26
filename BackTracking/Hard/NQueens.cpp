import java.util.*;

class Solution {

    private boolean isSafe(List<StringBuilder> board, int i, int j) {
        for (int x = 0; x < i; x++) {
            for (int y = 0; y < board.size(); y++) {
                if (board.get(x).charAt(y) == 'Q') {
                    if (y == j || Math.abs(x - i) == Math.abs(y - j)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    private void fun(int i, int n, List<List<String>> ans, List<StringBuilder> board) {
        if (i == n) {
            List<String> temp = new ArrayList<>();
            for (StringBuilder row : board) temp.add(row.toString());
            ans.add(temp);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, i, j)) {
                board.get(i).setCharAt(j, 'Q');
                fun(i + 1, n, ans, board);
                board.get(i).setCharAt(j, '.'); // backtrack
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();

        List<StringBuilder> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            board.add(new StringBuilder(".".repeat(n)));
        }

        fun(0, n, ans, board);
        return ans;
    }
}