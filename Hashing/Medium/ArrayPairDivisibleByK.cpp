Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

Example 1 :

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

one number should have remainder x and other as k-x
k/2->even frequency
https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1/
import java.util.*;

class Solution {
    public boolean canPair(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();

        // Count remainders
        for (int num : nums) {
            int rem = num % k;
            if (rem < 0) rem += k; // handle negative numbers
            map.put(rem, map.getOrDefault(rem, 0) + 1);
        }

        // Check pairing conditions
        for (int num : nums) {
            int rem = num % k;
            if (rem < 0) rem += k;

            if (rem == 0) {
                // must be even frequency
                if (map.get(rem) % 2 != 0) return false;
            } 
            else if (2 * rem == k) {
                // special case like k=10, rem=5
                if (map.get(rem) % 2 != 0) return false;
            } 
            else {
                int rem2 = k - rem;
                if (map.getOrDefault(rem, 0) != map.getOrDefault(rem2, 0))
                    return false;
            }
        }

        return true;
    }
}





Instead of looping twice, loop over map keys:

for (int rem : map.keySet()) {
    if (rem == 0 || 2 * rem == k) {
        if (map.get(rem) % 2 != 0) return false;
    } else {
        if (!map.get(rem).equals(map.getOrDefault(k - rem, 0)))
            return false;
    }
}



Given an array A[] and positive integer K, the task is to count total number of pairs in the array whose sum is divisible by K.

Example 1:

Input : 
A[] = {2, 2, 1, 7, 5, 3}, K = 4
Output : 5
Explanation : 
There are five pairs possible whose sum
is divisible by '4' i.e., (2, 2), 
(1, 7), (7, 5), (1, 3) and (5, 3)
https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
import java.util.*;

class Solution {
    public int countKdivPairs(int[] A, int K) {
        Map<Integer, Integer> map = new HashMap<>();
        int count = 0;

        for (int num : A) {
            int rem = num % K;
            if (rem < 0) rem += K; // handle negatives

            int rem2 = (K - rem) % K;

            if (map.containsKey(rem2)) {
                count += map.get(rem2);
            }

            map.put(rem, map.getOrDefault(rem, 0) + 1);
        }

        return count;
    }
}


class Solution {
    public int countKdivPairs(int[] A, int K) {
        int[] freq = new int[K];
        int count = 0;

        for (int num : A) {
            int rem = num % K;
            if (rem < 0) rem += K;

            int rem2 = (K - rem) % K;
            count += freq[rem2];

            freq[rem]++;
        }

        return count;
    }
}



Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return true If you can find a way to do that or false otherwise.

class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] freq = new int[k];

        // Count normalized remainders
        for (int num : arr) {
            int rem = ((num % k) + k) % k; // handle negatives
            freq[rem]++;
        }

        // Check remainder 0
        if (freq[0] % 2 != 0) return false;

        // Check pairs (i, k-i)
        for (int i = 1; i < k; i++) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }

        return true;
    }
}


for (int i = 1; i <= k / 2; i++) {
    if (i == k - i) { // middle element
        if (freq[i] % 2 != 0) return false;
    } else {
        if (freq[i] != freq[k - i]) return false;
    }
}