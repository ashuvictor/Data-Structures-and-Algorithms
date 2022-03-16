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
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
   int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
   int steps = 0;
   queue<pair<int, int>> q;
   int p = KnightPos[0] ;
   int f = KnightPos[1] ;

   q.push({p, f});

   bool visited[N+1][N+1];
   for (int i = 0; i <= N; i++)
   {
       for (int j = 0; j <= N; j++)
       {
           visited[i][j] = false;
       }
   }
   visited[p][f]=true;
   while (!q.empty())
   {
       int fl = q.size();
       for (int x = 0; x < fl; x++)
       {

           int i = q.front().first;
           int j = q.front().second;
           q.pop();

           if (i == TargetPos[0] && j == TargetPos[1])
               return steps;
           for (int f = 0; f < 8; f++)
           {
               int l = i + dx[f];
               int r = j + dy[f];
               if (l >= 1 && l <=N && r >= 1 && r <=N && !visited[l][r])
               {
                   visited[l][r] = true;
                   q.push({l, r});
               }
           }
       }
       steps++;
   }
   return steps;
} // Code here