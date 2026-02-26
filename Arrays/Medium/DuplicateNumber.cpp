/* DUPLICATE NUMBER IN ARRAY 
https://leetcode.com/problems/find-the-duplicate-number/
https://www.interviewbit.com/problems/find-duplicate-in-array/
*/
 Approach 1 — Negative Marking (Modifies Array)

⚠️ Works only if modifying array is allowed.

Java 21 Version
class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int idx = Math.abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                return Math.abs(nums[i]);
            }

            nums[idx] = -nums[idx];
        }

        return -1;
    }
}
🧠 Idea

Use values as indices

Mark visited by making negative

If already negative → duplicate found

❌ Downsides

Modifies input

Not allowed in LeetCode 287 constraints

✅ Approach 2 — Floyd’s Cycle Detection (BEST)

👉 Tortoise and Hare algorithm
👉 Does NOT modify array
👉 O(1) space

Java 21 Version
class Solution {
    public int findDuplicate(int[] nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find intersection
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find entrance to cycle
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
}
