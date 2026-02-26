/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/
import java.util.*;

class Solution {

    public boolean isValid(int[] weights, int days, int mid) {
        int sum = 0;
        int reqDays = 1;

        for (int w : weights) {
            sum += w;
            if (sum > mid) {
                reqDays++;
                sum = w;
            }
            if (reqDays > days)
                return false;
        }
        return true;
    }

    public int shipWithinDays(int[] weights, int days) {
        int mx = -1;
        int sum = 0;

        for (int w : weights) {
            mx = Math.max(mx, w);
            sum += w;
        }

        if (days == weights.length)
            return mx;

        int start = mx, end = sum;
        int ans = 0;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (isValid(weights, days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
}