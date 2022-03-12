There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

https://leetcode.com/problems/pacific-atlantic-water-flow/
class Solution {
public:
    void solve(vector<vector<int>>&heights,int i,int j,int prev,vector<vector<int>>&ocean){
        if(i<0 or i>=heights.size() or j<0 or j>=heights[0].size())
            return;
        if(ocean[i][j]==1)
            return;
        if(heights[i][j]<prev)
            return;
        ocean[i][j]=1;
        solve(heights,i+1,j,heights[i][j],ocean);
          solve(heights,i,j-1,heights[i][j],ocean);
          solve(heights,i,j+1,heights[i][j],ocean);
          solve(heights,i-1,j,heights[i][j],ocean);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        if(heights.size()<1)
            return ans;
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>pacific(m,vector<int>(n,0));
         vector<vector<int>>atlantic(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            solve(heights,i,0,INT_MIN,pacific);
            solve(heights,i,n-1,INT_MIN,atlantic);
        }
        for(int i=0;i<n;i++){
            solve(heights,0,i,INT_MIN,pacific);
            solve(heights,m-1,i,INT_MIN,atlantic);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]==1 and atlantic[i][j]==1)
                {
                    vector<int>temp(2);
                    temp[0]=i;
                    temp[1]=j;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
        
    }
};