/* MOORE VOTING ALGORITHM 
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.
 https://leetcode.com/problems/majority-element/
 */
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int candidate = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
            }

            if (x == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
}
/*Given an integer array of size n,
 find all elements that appear more than ⌊ n/3 ⌋ times.
 https://leetcode.com/problems/majority-element-ii/
 */
 import java.util.*;

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;

        int num1 = 0, num2 = 0;
        int count1 = 0, count2 = 0;

        // Step 1: Find candidates
        for (int x : nums) {
            if (x == num1) {
                count1++;
            } else if (x == num2) {
                count2++;
            } else if (count1 == 0) {
                num1 = x;
                count1 = 1;
            } else if (count2 == 0) {
                num2 = x;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify candidates
        count1 = 0;
        count2 = 0;

        for (int x : nums) {
            if (x == num1) count1++;
            else if (x == num2) count2++;
        }

        if (count1 > n / 3) ans.add(num1);
        if (count2 > n / 3) ans.add(num2);

        return ans;
    }
}
