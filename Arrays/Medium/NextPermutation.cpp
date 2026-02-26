/* NEXT PERMUTATION 
https://leetcode.com/problems/next-permutation/
*/
import java.util.*;

class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;

        int k;
        // Step 1: Find first decreasing element from right
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) break;
        }

        // Step 2: If no pivot → reverse whole array
        if (k < 0) {
            reverse(nums, 0, n - 1);
        } else {
            // Step 3: Find next greater element from right
            int s;
            for (s = n - 1; s > k; s--) {
                if (nums[s] > nums[k]) break;
            }

            swap(nums, s, k);

            // Step 4: Reverse suffix
            reverse(nums, k + 1, n - 1);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void reverse(int[] nums, int l, int r) {
        while (l < r) {
            swap(nums, l++, r--);
        }
    }
}
