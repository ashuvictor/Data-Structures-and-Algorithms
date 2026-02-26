Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.
https://www.interviewbit.com/problems/meeting-rooms/

import java.util.*;

public class Solution {
    public int solve(ArrayList<ArrayList<Integer>> A) {
        
        // Sort by start time (same as sort(A.begin(), A.end()))
        A.sort((a, b) -> a.get(0) - b.get(0));

        // Min heap of end times
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < A.size(); i++) {
            int start = A.get(i).get(0);
            int end = A.get(i).get(1);

            if (pq.isEmpty()) {
                pq.offer(end);
            } else {
                if (pq.peek() <= start) {
                    pq.poll();       // reuse room
                    pq.offer(end);
                } else {
                    pq.offer(end);   // new room
                }
            }
        }

        return pq.size();
    }
}