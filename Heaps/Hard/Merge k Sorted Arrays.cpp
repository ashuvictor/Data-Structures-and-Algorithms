Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].


#define pii pair<int,pair<int,int>>
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue< pii, vector<pii>, greater<pii>> pq;
        vector<int> res;
        for(int i=0;i<k;i++) pq.push({arr[i][0],{i,0}});
        
        while(res.size()<k*k){
            pii cur= pq.top();
            int val= cur.first;
            int col= cur.second.second;
            int row= cur.second.first;
            
            pq.pop();
            res.push_back(val);
            if(col+1<k) pq.push({arr[row][col+1],{row, col+1}});
        }
        
        return res;
    }
};