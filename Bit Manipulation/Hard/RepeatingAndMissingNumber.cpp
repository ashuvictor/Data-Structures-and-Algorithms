/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
https://www.interviewbit.com/problems/repeat-and-missing-number-array/
*/
brute force
using the hashmap 
nother approach is using the sign trick
vector<int> Solution::repeatedNumber(const vector<int> &A) {
  int n=A.size();
  int xo=0;
  for(int i=0;i<A.size();i++){
      xo=xo^A[i];
      xo=xo^(i+1);
  }
  int setBit=xo&(-xo);// int setbit=xo&(~(xo-1))
  int x=0,y=0;
  for(int i=0;i<n;i++){
      if(A[i]&setBit)
      x=x^A[i];
      else
      y=y^A[i];
      if((i+1)&setBit)
      x=x^(i+1);
      else
      y=y^(i+1);
  }
  vector<int>res(2);
  for(int i=0;i<n;i++){
      if(A[i]==x){
          res[0]=x;
          res[1]=y;break;
      }
      else if(A[i]==y)
      {
          res[0]=y;
          res[1]=x;break;
      }
  }
  return res;
}