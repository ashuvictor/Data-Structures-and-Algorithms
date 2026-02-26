import java.util.*;

class Solution {

    private void solve(int[] A, List<List<Integer>> ans, int i) {
        if (i == A.length) {
            List<Integer> perm = new ArrayList<>();
            for (int num : A) perm.add(num);
            ans.add(perm);
            return;
        }

        for (int j = i; j < A.length; j++) {
            swap(A, i, j);
            solve(A, ans, i + 1);
            swap(A, i, j); // backtrack
        }
    }

    private void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    public List<List<Integer>> permute(int[] A) {
        List<List<Integer>> ans = new ArrayList<>();
        solve(A, ans, 0);
        return ans;
    }
}