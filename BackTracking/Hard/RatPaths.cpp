Rat in a Maze
class Solution{
    public:
    void solve(vector<string>&ans,vector<vector<int>>&m,int n,int i,int j,string path)
    {
        if(i<0 or i>=n or j<0 or j>=n or m[i][j]!=1)
        {
            return;
        }
        if(i==n-1 and j==n-1)
        {
            ans.push_back(path);return;
        }
        m[i][j]=-1;//mark as visited
        solve(ans,m,n,i+1,j,path+'D');
        solve(ans,m,n,i,j-1,path+'L');
        solve(ans,m,n,i,j+1,path+'R');
        solve(ans,m,n,i-1,j,path+'U');
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
      vector<string>ans;
      solve(ans,m,n,0,0,"");
      return ans;
    }
};

methods2
class Solution{
    public:
    void solve(int i,int j,vector<vector<int>>&a,int n,vector<string>&ans,string move, vector<vector<int>> &vis,int dx[],int dy[]){
        if(i==n-1 and j==n-1){
            ans.push_back(move);
            return;
        }
        string dir="DLRU";
        for(int ind=0;ind<4;ind++){
            int nexti=i+dx[ind];
            int nextj=j+dy[ind];
            if(nexti>=0 and nextj>=0 and nexti<n and nextj<n and vis[nexti][nextj]==false and a[nexti][nextj]==1)
        {
            vis[i][j]=1;
              solve(nexti,nextj,a,n,ans,move + dir[ind],vis,dx,dy);
           vis[i][j] = 0;
        }
            
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        if(m[0][0]==1)
        solve(0,0,m,n,ans,"",vis,dx,dy);
        return ans;
        
    }
};

    