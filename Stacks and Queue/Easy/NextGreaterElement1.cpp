https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
import java.util.*;

class Solution {

    public long[] nextLargerElement(long[] arr, int n) {
        long[] ans = new long[n];
        Stack<Long> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            long current = arr[i];

            while (!stack.isEmpty() && current > stack.peek()) {
                stack.pop();
            }

            ans[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(current);
        }

        return ans;
    }
}



public long[] nextLargerElement(long[] arr, int n) {
    long[] ans = new long[n];
    Deque<Long> stack = new ArrayDeque<>();

    for (int i = n - 1; i >= 0; i--) {
        while (!stack.isEmpty() && arr[i] >= stack.peek()) {
            stack.pop();
        }

        ans[i] = stack.isEmpty() ? -1 : stack.peek();
        stack.push(arr[i]);
    }

    return ans;
}