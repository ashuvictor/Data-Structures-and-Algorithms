Approach 1 — Kadane Variant (Best)

👉 Track both max and min because of negatives.

Java 21 Version
class Solution {
    public int maxProduct(int[] nums) {
        int maxp = nums[0];
        int minp = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < 0) {
                int temp = maxp;
                maxp = minp;
                minp = temp;
            }

            minp = Math.min(minp * nums[i], nums[i]);
            maxp = Math.max(maxp * nums[i], nums[i]);

            ans = Math.max(ans, maxp);
        }

        return ans;
    }
}
🧠 Why Track min?

Because:

(-2) * (-3) = +6

A small negative can become a big positive.

✅ Approach 2 — Left to Right + Right to Left

👉 Handles zero splitting naturally.

Java 21 Version
class Solution {
    public int maxProduct(int[] nums) {
        int ans = Integer.MIN_VALUE;
        int prod = 1;

        // Left to right
        for (int i = 0; i < nums.length; i++) {
            prod *= nums[i];
            ans = Math.max(ans, prod);
            if (prod == 0) prod = 1;
        }

        // Right to left
        prod = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            prod *= nums[i];
            ans = Math.max(ans, prod);
            if (prod == 0) prod = 1;
        }

        return ans;
    }
}
