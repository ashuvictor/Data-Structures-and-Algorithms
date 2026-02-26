/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
https://leetcode.com/problems/product-of-array-except-self/
*/
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];

        int p = 1;

        // Prefix products
        for (int i = 0; i < n; i++) {
            ans[i] = p;
            p *= nums[i];
        }

        // Suffix products
        p = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= p;
            p *= nums[i];
        }

        return ans;
    }
}
