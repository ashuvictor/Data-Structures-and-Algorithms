https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1/?category

import java.util.*;

class Solution {
    static int maxMeetings(int[] start, int[] end, int n) {

        // Store meetings as [start, end]
        int[][] timing = new int[n][2];
        for (int i = 0; i < n; i++) {
            timing[i][0] = start[i];
            timing[i][1] = end[i];
        }

        // Sort by end time, then start time
        Arrays.sort(timing, (a, b) -> {
            if (a[1] == b[1]) return a[0] - b[0];
            return a[1] - b[1];
        });

        int i = 0, j = 1;
        int ans = 1;

        while (j < n) {
            if (timing[i][1] < timing[j][0]) {
                ans++;
                i = j;
            }
            j++;
        }

        return ans;
    }
}