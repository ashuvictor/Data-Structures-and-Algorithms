Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the length of maximal set of mutually disjoint intervals.

Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.

Return a integer denoting the length of maximal set of mutually disjoint intervals.



Problem Constraints
1 <= N <= 105

1 <= A[i][0] <= A[i][1] <= 109



Input Format
First and only argument is a 2D array A of size N x 2 denoting the N intervals.



Output Format
Return a integer denoting the length of maximal set of mutually disjoint intervals.



Example Input
Input 1:

 A = [
       [1, 4]
       [2, 3]
       [4, 6]
       [8, 9]
     ]
Input 2:

 A = [
       [1, 9]
       [2, 3]
       [5, 7]
     ]


Example Output
Output 1:

 3
Output 2:

 2
https://www.interviewbit.com/problems/disjoint-intervals/

import java.util.*;

public class Solution {
    public int solve(ArrayList<ArrayList<Integer>> A) {
        // Sort intervals lexicographically
        A.sort((a, b) -> {
            if (!a.get(0).equals(b.get(0))) {
                return a.get(0) - b.get(0);
            }
            return a.get(1) - b.get(1);
        });

        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>(A.get(0)));

        for (int i = 1; i < A.size(); i++) {
            ArrayList<Integer> last = ans.get(ans.size() - 1);
            ArrayList<Integer> curr = A.get(i);

            if (last.get(1) >= curr.get(0)) {
                // Merge by shrinking end (same as your C++ logic)
                last.set(1, Math.min(last.get(1), curr.get(1)));
            } else {
                ans.add(new ArrayList<>(curr));
            }
        }

        return ans.size();
    }
}
