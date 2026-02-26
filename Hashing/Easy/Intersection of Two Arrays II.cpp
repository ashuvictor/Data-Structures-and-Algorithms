Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
import java.util.*;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        List<Integer> ans = new ArrayList<>();

        // Count elements from nums1
        for (int x : nums1) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        // Match elements from nums2
        for (int y : nums2) {
            if (map.getOrDefault(y, 0) > 0) {
                ans.add(y);
                map.put(y, map.get(y) - 1);
            }
        }

        // Convert List → array
        int[] res = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }

        return res;
    }
}
