 /*FIRST AND LAST POSITION OF A ELEMENT IN A SORTED ARRAY USING BINARY SEARCH
 https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */
class Solution {

    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1, -1};

        int low = 0, high = nums.length - 1;

        // Find first occurrence
        while (low <= high) {
            int mid = (low + high) >> 1;

            if (nums[mid] == target) {
                ans[0] = mid;
                high = mid - 1; // move left
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Find last occurrence
        if (ans[0] != -1) {
            low = 0;
            high = nums.length - 1;

            while (low <= high) {
                int mid = (low + high) >> 1;

                if (nums[mid] == target) {
                    ans[1] = mid;
                    low = mid + 1; // move right
                } else if (nums[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return ans;
    }
}