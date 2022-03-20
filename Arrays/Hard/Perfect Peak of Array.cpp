

https://www.interviewbit.com/problems/perfect-peak-of-array/
Problem Description

Given an integer array A of size N.

You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.

If it exists return 1 else return 0.

NOTE:

Do not consider the corner elements i.e A[0] and A[N-1] as the answer.


Problem Constraints
3 <= N <= 105

1 <= A[i] <= 109



Input Format
First and only argument is an integer array A containing N integers.



Output Format
Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly  smaller than all the elements on right of it else return 0.



Example Input
Input 1:

 A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
Input 2:

 A = [5, 1, 4, 4]


Example Output
Output 1:

 1
Output 2:

 0
int Solution::perfectPeak(vector<int> &A) {
 
     int n= A.size();
  vector<int> prefix(n);
  vector<int > suffix(n);
  
  prefix[0]= A[0];

  for(int i=1;i<A.size();i++){
      prefix[i]= max(prefix[i-1], A[i]);
  }
  suffix[n-1]= A[n-1];
  for(int i= n-2;i>=0;i--){
      suffix[i]= min(suffix[i+1], A[i]);
  }
    
  for(int i=1;i<=n-2;i++){
      if(prefix[i-1]<A[i] && A[i]<suffix[i+1]){
          return 1;
      }
  }
    return 0;
      
}
