https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1/?category
import java.util.*;

class Job {
    int id, dead, profit;
    Job(int id, int dead, int profit) {
        this.id = id;
        this.dead = dead;
        this.profit = profit;
    }
}

class Solution {

    public int[] JobScheduling(Job[] arr, int n) {

        // Sort by profit descending
        Arrays.sort(arr, (a, b) -> b.profit - a.profit);

        boolean[] done = new boolean[n];
        int day = 0, profit = 0;

        for (int i = 0; i < n; i++) {
            // Try latest possible slot
            for (int j = Math.min(n, arr[i].dead) - 1; j >= 0; j--) {
                if (!done[j]) {
                    done[j] = true;
                    day++;
                    profit += arr[i].profit;
                    break;
                }
            }
        }

        return new int[]{day, profit};
    }
}