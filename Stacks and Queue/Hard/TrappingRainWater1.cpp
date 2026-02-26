/*brute force will
https://leetcode.com/problems/trapping-rain-water/
for every building min(max_left_building,max_right_building)-heights[i]
keep on adding it to the ans
*/
import java.util.*;

class Solution {

    public int trap(int[] height) {
        int n = height.length;
        if (n <= 2) return 0;

        int[] left = new int[n];
        int[] right = new int[n];

        int leftMax = height[0];
        left[0] = 0;

        // build left max array
        for (int i = 1; i < n; i++) {
            left[i] = leftMax;
            leftMax = Math.max(leftMax, height[i]);
        }

        int rightMax = height[n - 1];
        right[n - 1] = height[n - 1];

        // build right max array
        for (int i = n - 2; i >= 0; i--) {
            right[i] = rightMax;
            rightMax = Math.max(rightMax, height[i]);
        }

        int ans = 0;

        // calculate trapped water
        for (int i = 1; i < n; i++) {
            if (height[i] < left[i] && height[i] < right[i]) {
                ans += Math.min(left[i], right[i]) - height[i];
            }
        }

        return ans;
    }
}


class Solution {

    public int trap(int[] height) {
        int n = height.length;
        int left = 0, right = n - 1;

        int res = 0;
        int maxLeft = 0, maxRight = 0;

        while (left <= right) {

            if (height[left] <= height[right]) {

                if (height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    res += maxLeft - height[left];

                left++;
            } else {

                if (height[right] >= maxRight)
                    maxRight = height[right];
                else
                    res += maxRight - height[right];

                right--;
            }
        }

        return res;
    }
}