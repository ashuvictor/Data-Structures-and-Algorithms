



Problem Statement: There is a new barn with N stalls and C cows. The stalls are located on a straight line at positions x1,….,xN (0 <= xi <= 1,000,000,000). We want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

Examples:

Input: No of stalls = 5 
       Array: {1,2,8,4,9}
       And number of cows: 3

Output: One integer, the largest minimum distance 3
Solution 1: Brute Force

Intuition: 

It’s required that we put all the C cows into our stalls. So for a start, let’s say we set the minimum distance = 1 and put them consecutively. These cows fit perfectly.

This is too close, so let’s increase our minimum distance a bit. Let’s increase the distance further to 2. We can again check that the cows can be accommodated. 

But we want to reduce the possibility of collision/fighting as much as possible, so we keep on increasing the minimum distance. Here is an illustration:

import java.util.*;

public class Main {

    static boolean isCompatible(List<Integer> inp, int dist, int cows) {
        int n = inp.size();
        int k = inp.get(0);
        cows--;

        for (int i = 1; i < n; i++) {
            if (inp.get(i) - k >= dist) {
                cows--;
                if (cows == 0) {
                    return true;
                }
                k = inp.get(i);
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int n = 5, m = 3;
        List<Integer> inp = new ArrayList<>(Arrays.asList(1, 2, 8, 4, 9));

        Collections.sort(inp);

        int maxD = inp.get(n - 1) - inp.get(0);
        int ans = Integer.MIN_VALUE;

        for (int d = 1; d <= maxD; d++) {
            boolean possible = isCompatible(inp, d, m);
            if (possible) {
                ans = Math.max(ans, d);
            }
        }

        System.out.println("The largest minimum distance is " + ans);
    }
}



solution 2
 import java.util.Arrays;

public class Main {

    static boolean isPossible(int[] a, int n, int cows, int minDist) {
        int cntCows = 1;
        int lastPlacedCow = a[0];

        for (int i = 1; i < n; i++) {
            if (a[i] - lastPlacedCow >= minDist) {
                cntCows++;
                lastPlacedCow = a[i];
            }
        }
        return cntCows >= cows;
    }

    public static void main(String[] args) {
        int n = 5, cows = 3;
        int[] a = {1, 2, 8, 4, 9};

        Arrays.sort(a);

        int low = 1, high = a[n - 1] - a[0];

        while (low <= high) {
            int mid = (low + high) >> 1;

            if (isPossible(a, n, cows, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        System.out.println("The largest minimum distance is " + high);
    }
}
Output: The largest minimum distance is 3

Time Complexity: O(N*log(M)). 

Reason: For binary search in a space of M, O(log(M))  and for each search, we iterate over max N stalls to check. O(N).