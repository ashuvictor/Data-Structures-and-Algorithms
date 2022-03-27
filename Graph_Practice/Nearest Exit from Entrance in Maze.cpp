https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.
class Solution {
public:
    int v[4] = {1,0,0,-1};
    int v1[4]={0,-1,1,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>>pq;
        pq.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int moves = 0;
        while(!pq.empty()){
            moves++;
            int l = pq.size();
            for(int a = 0; a<l; a++){
                auto [i, j] = pq.front();
                pq.pop();
                for (int k = 0; k < 4; k++)
                {
                    int x = i + v[k];
                    int y = j + v1[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.')
                    {
                        if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
                            return moves;
                        maze[x][y] = '+';
                        pq.push({x, y});
                    }
               }
            }
        }
        return -1;
    }
};