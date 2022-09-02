
https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1/
Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 


class Solution
{
public:
    void helper(vector<vector<char>>&mat,int i,int j)
    {
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]!='O')
        {
            return;
        }
        mat[i][j]='#';
        helper(mat,i-1,j);
        helper(mat,i+1,j);
        helper(mat,i,j-1);
        helper(mat,i,j+1);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        n=mat.size();
        m=mat[0].size();
        // populate the 'O's which are connected to the boundary
        for(int j=0;j<mat[0].size();j++)
        {
            if(mat[0][j]=='O')
            {
                helper(mat,0,j);
            }
        }
        for(int i=0;i<mat.size();i++)
        {
            if(mat[i][m-1]=='O')
            {
                helper(mat,i,m-1);
            }
        }
        for(int j=mat[0].size()-1;j>=0;j--)
        {
            if(mat[n-1][j]=='O')
            {
                helper(mat,n-1,j);
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(mat[i][0]=='O')
            {
                helper(mat,i,0);
            }
        }
        
        // Now fill all the 'O's with 'X'
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O')
                {
                    mat[i][j]='X';
                }
            }
        }
        
        // Now restore the '#' cause they are actually 'O's
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='#')
                {
                    mat[i][j]='O';
                }
            }
        }
        return mat;
    }
};




//METHOD-1

class Solution {
    bool seen;
    void mark(vector<vector<char>>& board,int i,int j,int r,int c)
    {
        if(i<0 || i>r-1 || j<0 || j>c-1)
            return;
        if(board[i][j]=='X')
            return;
        
        board[i][j] = 'X';
        mark(board,i-1,j,r,c);
        mark(board,i+1,j,r,c);
        mark(board,i,j-1,r,c);
        mark(board,i,j+1,r,c);       
    }
    void dfs(vector<vector<char>>& board,int i,int j,int r,int c,vector<vector<bool>>& visited)
    {
        if(i<0 || i>r-1 || j<0 || j>c-1)
            return;
        
        if(board[i][j]=='X' || visited[i][j])
            return;
        if(i<=0 || i>=r-1 || j<=0 || j>=c-1)
            seen = true;
        
        visited[i][j] = true;
        dfs(board,i-1,j,r,c,visited);
        dfs(board,i+1,j,r,c,visited);
        dfs(board,i,j-1,r,c,visited);
        dfs(board,i,j+1,r,c,visited);
    }
public:
    void solve(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int r=board.size();
        if(r<=1)
            return;
        int c=board[0].size();
        if(c<=1)
            return;
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        
        for(int i=1;i<r-1;++i)
        {
            for(int j=1;j<c-1;++j)
            {
                if(board[i][j]=='O' && !visited[i][j])
                {
                    seen = false;
                    dfs(board,i,j,r,c,visited);
                    if(seen==false)
                        mark(board,i,j,r,c);
                    seen = true;
                }
            }
        }
    }
};

//METHOD-2

void dfs(vector<vector<char>>& grid, int i, int j)
{
    if(grid[i][j] == 'O'){
        
        grid[i][j] = '1';

        if(i+1 < grid.size()) dfs(grid, i+1, j);
        if(i > 1) dfs(grid, i-1, j);
        if(j+1 < grid[i].size()) dfs(grid, i, j+1);
        if(j > 1) dfs(grid, i, j-1);
    }
}
class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return;
        int row = grid.size(), col = grid[0].size();
        
        //first row and last row
        for(int i=0; i<row; i++){
            dfs(grid, i, 0);
            dfs(grid, i, col-1);
        }
        //first col and last col
        for(int j=1; j<col-1; j++){
            dfs(grid, 0, j);
            dfs(grid, row-1, j);
        }
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == 'O') grid[i][j] = 'X';
                else if (grid[i][j] == '1') grid[i][j] = 'O';
    }
};