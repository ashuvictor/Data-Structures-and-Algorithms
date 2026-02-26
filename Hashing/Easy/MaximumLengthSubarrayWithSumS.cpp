/*Find maximum length subarray having a given sum
https://techiedelight.com/practice/?problem=MaximumLengthSubarray

*/
class Solution {
    public void findMaxLenSubarray(int[] nums, int S) {
        int n = nums.length;

        int len = 0;
        int endingIndex = -1;

        // All starting points
        for (int i = 0; i < n; i++) {
            int target = 0;

            // All ending points
            for (int j = i; j < n; j++) {
                target += nums[j];

                if (target == S) {
                    if (len < j - i + 1) {
                        len = j - i + 1;
                        endingIndex = j;
                    }
                }
            }
        }

        if (endingIndex == -1) {
            System.out.println("No subarray found");
        } else {
            System.out.println("[" + (endingIndex - len + 1) + ", " + endingIndex + "]");
        }
    }
}
METHOD 2
import java.util.*;

class Solution {
    public void findMaxLenSubarray(int[] nums, int S) {
        Map<Integer, Integer> map = new HashMap<>();
        int sum = 0;
        int maxLen = 0;
        int endIndex = -1;

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];

            // Case 1: whole array till i
            if (sum == S) {
                maxLen = i + 1;
                endIndex = i;
            }

            // Case 2: prefix seen before
            if (map.containsKey(sum - S)) {
                int start = map.get(sum - S) + 1;
                int len = i - map.get(sum - S);
                if (len > maxLen) {
                    maxLen = len;
                    endIndex = i;
                }
            }

            // Store first occurrence only
            map.putIfAbsent(sum, i);
        }

        if (endIndex == -1)
            System.out.println("No subarray found");
        else
            System.out.println("[" + (endIndex - maxLen + 1) + ", " + endIndex + "]");
    }
}
