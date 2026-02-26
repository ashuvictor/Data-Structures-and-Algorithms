https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0


class Solution {

    public int countNegatives(int[][] grid) {
        int count = 0;
        for (int[] row : grid) {
            count += countRow(row);
        }
        return count;
    }

    private int countRow(int[] v) {
        int beg = 0, end = v.length - 1;
        int pos = -1;

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;

            if (v[mid] < 0) {
                pos = mid;
                end = mid - 1; // search left
            } else {
                beg = mid + 1;
            }
        }

        if (pos != -1)
            return v.length - pos;

        return 0;
    }
}
class Solution {

    public int countNegatives(int[][] grid) {
        int i = 0;
        int j = grid[0].length - 1;

        int n = grid.length;
        int count = 0;

        while (i <= n - 1 && j >= 0) {
            if (grid[i][j] < 0) {
                count += (n - i); // all elements below are negative
                j--; // move left
            } else {
                i++; // move down
            }
        }

        return count;
    }
}