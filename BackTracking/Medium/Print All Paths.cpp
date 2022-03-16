Print all possible paths from top left to bottom right of a mXn matrix
Difficulty Level : Medium
Last Updated : 25 Jan, 2022
The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Examples : 

Input : 1 2 3
        4 5 6
Output : 1 4 5 6
         1 2 5 6
         1 2 3 6

Input : 1 2 
        3 4
Output : 1 2 4
         1 3 4

#include <bits/stdc++.h>

using namespace std;

void findpaths(int x,int y,int rows,int cols,vector<vector<int>> mat,vector<vector<bool>>&visited,vector<int> path,vector<vector<int>>&allpaths)
{
    if(x==rows-1 && y==cols-1)
    {
        path.push_back(mat[x][y]);
        allpaths.push_back(path);
        return;
    }
    
    if(x<0 || x>=rows || y<0 || y>=cols || visited[x][y])
        return;
    
    path.push_back(mat[x][y]);
    visited[x][y]=true;
    findpaths(x,y+1,rows,cols,mat,visited,path,allpaths);
    findpaths(x+1,y,rows,cols,mat,visited,path,allpaths);
    visited[x][y]=false;
    path.pop_back();
    
}
int main()
{
    int rows,cols;
    cin>>rows>>cols;
	vector<vector<int>> mat(rows,vector<int> (cols,0));
	vector<vector<bool>> visited(rows,vector<bool> (cols,false));
	
	for(int i=0;i<rows;++i)
	{
	    for(int j=0;j<cols;++j)
	    {
	        cin>>mat[i][j];
	    }
	}
	

	vector<int> path;
	vector<vector<int>> allpaths;
	findpaths(0,0,rows,cols,mat,visited,path,allpaths);
	cout<<allpaths.size()<<endl;
	for(int i=0;i<allpaths.size();++i)
	{
	    for(int j=0;j<allpaths[i].size();++j)
	    {
	        cout<<allpaths[i][j]<<" ";
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}

