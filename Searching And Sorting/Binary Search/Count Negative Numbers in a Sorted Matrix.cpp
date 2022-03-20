https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c = 0;
        for(int i=0; i<grid.size(); i++){
            c+=count(grid[i]);
        }
        return c;
    }
    
    int count(vector<int>& v){
        int beg = 0;
        int end = v.size()-1;
        int mid;
        int pos = -1;
        while(beg<=end){
            mid = beg+(end-beg)/2;
            if(v[mid]<0){
                pos = mid;
                end = mid-1;
            }
            else if(v[mid]>=0){
                beg = mid+1;
            }
        }
        if(pos!=-1 && v[pos]<0){
            return v.size()-pos;
        }
        return 0;
    }
};
int countNegatives(vector<vector>& grid) {

   int i=0,j=grid[0].size()-1;
   int n=grid.size();int count=0;
    while(i<=n-1 and j>=0 ){
      if(grid[i][j]<0)
	  {count+=(n-i);j--;}// count till all down go left
      else{ //go down,no count here
          i++;
      }  
    }
    return count;
}