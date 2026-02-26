/*
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
*/
import java.util.*;

class Solution {

    // Count elements <= mid in a sorted row (upper bound)
    private int countSmaller(int[] row, int mid) {
        int l = 0, h = row.length - 1;

        while (l <= h) {
            int md = (l + h) >> 1;

            if (row[md] <= mid) {
                l = md + 1;
            } else {
                h = md - 1;
            }
        }
        return l; // number of elements <= mid
    }

    public int median(int[][] matrix, int r, int c) {
        int low = Integer.MIN_VALUE;
        int high = Integer.MAX_VALUE;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;

            for (int i = 0; i < r; i++) {
                cnt += countSmaller(matrix[i], mid);
            }

            if (cnt <= (r * c) / 2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
}