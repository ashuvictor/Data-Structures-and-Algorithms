Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing.

 

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#


class Solution 
{ int dx[8]={-2,-1,1,2,2,1,-1,-2};
  int dy[8]={1,2,2,1,-1,-2,-2,-1};
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    vector<vector<bool>>vis(N+1,vector<bool>(N+1,false));
	    vis[KnightPos[0]][KnightPos[1]]=true;
	    int ans=0;
	    while(!q.empty()){
	        int qsz=q.size();
	        while(qsz--){
	            int x1=q.front().first;
	            int y1=q.front().second;
	            q.pop();
	            if(x1==TargetPos[0] and y1==TargetPos[1])
	            return ans;
	            for(int i=0;i<8;i++){
	                vector<int>posNew={x1+dx[i],y1+dy[i]};
	                if(posNew[0]>=1 and posNew[0]<=N and posNew[1]>=1 and posNew[1]<=N and vis[posNew[0]][posNew[1]]==false)
	                {
	                    q.push({posNew[0],posNew[1]});
	                    vis[posNew[0]][posNew[1]]=true;
	                }
	            }
	        }
	        ans++;
	    }
	    return -1;
	}
};