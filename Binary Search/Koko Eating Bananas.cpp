/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
https://leetcode.com/problems/koko-eating-bananas/

*/
class Solution {

    private int funcTime(int mid, int[] piles) {
        int sum = 0;
        for (int pile : piles) {
            sum += (pile / mid) + ((pile % mid) != 0 ? 1 : 0);
        }
        return sum;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = 0;

        // max element
        for (int p : piles) {
            high = Math.max(high, p);
        }

        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int time = funcTime(mid, piles);

            if (time <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
}