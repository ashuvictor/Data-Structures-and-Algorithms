/*
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
*/
class Solution{   
public:
    int countSmaller(vector<int>&row,int mid){
        int l=0,h=row.size()-1;
           while(l <= h) {
        int md = (l + h) >> 1; 
        if(row[md] <= mid) {
            l = md + 1;
        }
        else {
            h = md - 1;
        }
    }
    return l; 

    }
    int median(vector<vector<int>> &matrix, int r, int c){
       int low=INT_MIN;
       int high=INT_MAX;
       while(low<=high){
           int mid=(low+high)>>1;
           int cnt=0;
           for(int i=0;i<r;i++){
               cnt+=countSmaller(matrix[i],mid);
           }
           if(cnt<=(r*c)/2)
           low=mid+1;
           else
           high=mid-1;
       }
       return low;
    }
};