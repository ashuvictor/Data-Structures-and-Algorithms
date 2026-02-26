
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
https://practice.geeksforgeeks.org/problems/minimum-swaps/1/
import java.util.*;

class Solution {

    static class Pair {
        int value, index;

        Pair(int v, int i) {
            value = v;
            index = i;
        }
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;

        Pair[] arr = new Pair[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        // Sort by value
        Arrays.sort(arr, Comparator.comparingInt(p -> p.value));

        int count = 0;

        for (int i = 0; i < n; i++) {
            // Already in correct place
            if (arr[i].index == i) continue;

            // Swap with correct position
            swap(arr, i, arr[i].index);
            count++;
            i--; // re-check this index
        }

        return count;
    }

    private void swap(Pair[] arr, int i, int j) {
        Pair temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}





import java.util.*;

class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;

        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }

        Arrays.sort(arr, Comparator.comparingInt(a -> a[0]));

        boolean[] visited = new boolean[n];
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i][1] == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j][1];
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
}
