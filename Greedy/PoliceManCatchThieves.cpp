  Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
Keep in mind the following conditions :

Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from him.
Example 1:

Input:
N = 5, K = 1
arr[] = {P, T, T, P, T}
Output: 2
Explanation: Maximum 2 thieves can be 
caught. First policeman catches first thief 
and second police man can catch either second 
or third thief.
https://practice.geeksforgeeks.org/problems/e47329920b4e75869ea7b0e9b7c59ea145ccc22c/1/#
  
  import java.util.*;

class Solution {
    public int catchThieves(char[] arr, int n, int k) {

        Queue<Integer> police = new LinkedList<>();
        Queue<Integer> thief = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') {
                police.offer(i);
            } else {
                thief.offer(i);
            }
        }

        int ans = 0;

        while (!police.isEmpty() && !thief.isEmpty()) {
            int p = police.peek();
            int t = thief.peek();

            if (Math.abs(p - t) <= k) {
                ans++;
                police.poll();
                thief.poll();
            } else if (p < t) {
                police.poll();
            } else {
                thief.poll();
            }
        }

        return ans;
    }
}




import java.util.*;

class Solution {
    public int catchThieves(char[] arr, int n, int k) {

        List<Integer> police = new ArrayList<>();
        List<Integer> thief = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (arr[i] == 'P') police.add(i);
            else thief.add(i);
        }

        int i = 0, j = 0, ans = 0;

        while (i < police.size() && j < thief.size()) {
            int p = police.get(i);
            int t = thief.get(j);

            if (Math.abs(p - t) <= k) {
                ans++;
                i++;
                j++;
            } else if (p > t) {
                j++;
            } else {
                i++;
            }
        }

        return ans;
    }
}