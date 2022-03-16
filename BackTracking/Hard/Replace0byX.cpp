iven a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
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

https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1/?page=1&difficulty[]=1&status[]=solved&category[]=Graph&sortBy=submissions







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