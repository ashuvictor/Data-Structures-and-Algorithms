
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

https://leetcode.com/problems/diagonal-traverse/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
      
        int row=0;
        int col=0;
        int i=0;
        bool flag=true;
        while(row<m and col<n)
        {
            if(flag)  //going up
            {
                while(row>0 and col<n-1)
                {
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                ans.push_back(mat[row][col]);
                if(col==n-1)
                {
                    row++;
                }
                else
                    col++;
               
                
            }
            else
            {
                while(col>0 and row<m-1){
                    ans.push_back(mat[row][col]);
                    col--;
                    row++;
                }
                ans.push_back(mat[row][col]);
                if(row==m-1)
                    col++;
                else
                    row++;
               
            }
              flag=!flag;
        }
        return ans;
    }
};


https://practice.geeksforgeeks.org/problems/print-diagonally4331/1#
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		// Your code goes here
		vector<int>ans;
		int row=0;
		int i=0;
		while(row<n){
		    int r=row;
		    int c=i;
		    while(r<n and c>=0)
		    {
		        ans.push_back(A[r][c]);
		        r++;c--;
		    }
		    if(i==n-1)
		    row++;
		    else
		    i++;
		}
		return ans;
	}

};