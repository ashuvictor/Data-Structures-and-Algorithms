Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
https://practice.geeksforgeeks.org/problems/knight-walk4521/1/?page=1&difficulty[]=1&status[]=solved&category[]=Graph&sortBy=submissions
import java.util.*;

class Solution {

    public int minStepToReachTarget(int[] KnightPos, int[] TargetPos, int N) {

        int[] dx = {-2, -1, 1, 2, -2, -1, 1, 2};
        int[] dy = {-1, -2, -2, -1, 1, 2, 2, 1};

        Queue<int[]> q = new LinkedList<>();

        int p = KnightPos[0];
        int f = KnightPos[1];

        q.offer(new int[]{p, f});

        boolean[][] visited = new boolean[N + 1][N + 1];
        visited[p][f] = true;

        int steps = 0;

        while (!q.isEmpty()) {
            int size = q.size();

            for (int x = 0; x < size; x++) {
                int[] curr = q.poll();
                int i = curr[0];
                int j = curr[1];

                if (i == TargetPos[0] && j == TargetPos[1])
                    return steps;

                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 1 && ni <= N && nj >= 1 && nj <= N && !visited[ni][nj]) {
                        visited[ni][nj] = true;
                        q.offer(new int[]{ni, nj});
                    }
                }
            }
            steps++;
        }
        return steps;
    }
}