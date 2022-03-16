Given an M x N matrix, with a few hurdles arbitrarily placed, calculate the length of the longest possible route possible 
from source to a destination within the matrix. We are allowed to move to only adjacent cells which are not hurdles.
 The route cannot contain any diagonal moves and a location once visited in a particular path cannot be visited again.
 https://www.youtube.com/watch?v=1iYB8h6W-Xs&list=PLlGpFGXC9XnYAL7SnEfyDwycO-9KIk_oq&index=7
 #include <bits/stdc++.h>

using namespace std;

void solve(int r,int c,vector<vector<int>> mat,vector<vector<bool>> visited,int &ans,int prow,int pcol,int dx,int dy,int pathlength)
{
    if(prow==dx && pcol==dy)
    {
        if(ans<pathlength)
            ans=pathlength;
            
        return;    
    }
    
    if(prow<0 ||pcol<0 || prow>=r || pcol>=c || visited[prow][pcol] || mat[prow][pcol]==0)//safe condition
        return;
    
    visited[prow][pcol]=true;
    solve(r,c,mat,visited,ans,prow,pcol+1,dx,dy,pathlength+1);
    solve(r,c,mat,visited,ans,prow,pcol-1,dx,dy,pathlength+1);
    solve(r,c,mat,visited,ans,prow-1,pcol,dx,dy,pathlength+1);
    solve(r,c,mat,visited,ans,prow+1,pcol,dx,dy,pathlength+1);
    visited[prow][pcol]=false;
    return;
}

int main()
{
    int r,c;
    cin>>r>>c;
    int x1,y1,x2,y2;
    
    vector<vector<int>> mat(r,vector<int> (c,0));
    
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            cin>>mat[i][j];
        }
    }
    
    cin>>x1>>y1;//source
    cin>>x2>>y2;//destination
    
    vector<vector<bool>> visited(r,vector<bool> (c,false));

    int ans=INT_MIN;
    if(mat[x1][y1]==0)
        cout<<"source point is a hurdle";
        
    else
    {
        solve(r,c,mat,visited,ans,x1,y1,x2,y2,0);
        cout<<"Maxmimum distance from source to destination is "<<endl;
        cout<<ans;
    }
    
	
	return 0;
}

