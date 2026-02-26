/*Given an integer rowIndex,
 return the rowIndexth (0-indexed) row of the Pascal's triangle.
 https://leetcode.com/problems/pascals-triangle-ii/
 */
import java.util.*;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> prev = new ArrayList<>();
        prev.add(1);

        for (int i = 1; i <= rowIndex; i++) {
            List<Integer> temp = new ArrayList<>();
            temp.add(1);

            for (int j = 1; j < i; j++) {
                temp.add(prev.get(j - 1) + prev.get(j));
            }

            temp.add(1);
            prev = temp;
        }

        return prev;
    }
}



Complexity

Time: O(n²)

Space: O(n)

🚀 Interview Upgrade (O(n) Space In-Place)

Using one list only (most asked optimization):

import java.util.*;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>();

        for (int i = 0; i <= rowIndex; i++) {
            row.add(1);
            for (int j = i - 1; j > 0; j--) {
                row.set(j, row.get(j) + row.get(j - 1));
            }
        }

        return row;
    }
}
