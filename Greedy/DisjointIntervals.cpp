Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the length of maximal set of mutually disjoint intervals.

Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.

Return a integer denoting the length of maximal set of mutually disjoint intervals.



Problem Constraints
1 <= N <= 105

1 <= A[i][0] <= A[i][1] <= 109



Input Format
First and only argument is a 2D array A of size N x 2 denoting the N intervals.



Output Format
Return a integer denoting the length of maximal set of mutually disjoint intervals.



Example Input
Input 1:

 A = [
       [1, 4]
       [2, 3]
       [4, 6]
       [8, 9]
     ]
Input 2:

 A = [
       [1, 9]
       [2, 3]
       [5, 7]
     ]


Example Output
Output 1:

 3
Output 2:

 2
https://www.interviewbit.com/problems/disjoint-intervals/

int Solution::solve(vector<vector<int> > &A) {
sort(A.begin(),A.end());
vector<vector<int>>ans;
ans.push_back(A[0]);
for(int i=1;i<A.size();i++){
    if(ans.back()[1]>=A[i][0])
    {
        ans.back()[1]=min(ans.back()[1],A[i][1]);
    }
    else{
        ans.push_back(A[i]);
    }
}
return ans.size();
}
