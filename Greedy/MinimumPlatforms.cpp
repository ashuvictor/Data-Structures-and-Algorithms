https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
import java.util.*;

class Solution {
    static int findPlatform(int[] arr, int[] dep, int n) {
        Arrays.sort(arr);
        Arrays.sort(dep);

        int ans = 1;
        int i = 1, j = 0;

        while (i < n) {
            if (arr[i] <= dep[j]) {
                ans++;
                i++;
            } else {
                j++;
                i++;
            }
        }

        return ans;
    }
}