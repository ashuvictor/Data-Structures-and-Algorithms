/*Subarray with zero sum
https://techiedelight.com/practice/?problem=ZeroSum
*/
import java.util.*;

class Solution {
    public boolean hasZeroSumSubarray(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        int sum = 0;

        for (int num : nums) {
            sum += num;

            if (sum == 0) return true;
            if (set.contains(sum)) return true;

            set.add(sum);
        }

        return false;
    }
}
