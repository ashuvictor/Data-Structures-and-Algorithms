
https://www.interviewbit.com/problems/maximum-sum-triplet/

Problem Description

Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.



Problem Constraints
3 <= N <= 105.

1 <= A[i] <= 108.



Input Format
First argument is an integer array A.



Output Format
Return a single integer denoting the maximum sum of triplet as described in the question.



Example Input
Input 1:

 A = [2, 5, 3, 1, 4, 9]
Input 2:

 A = [1, 2, 3]

 int Solution::solve(vector<int> &A) {
 
    int n=A.size();int ans=0;
    if(n<3)
    return ans;
    else{ 
for(int i=0;i<n-2;i++){
    for(int j=i+1;j<n-1;j++){
        if(A[j]<A[i])
        continue;
        for(int k=j+1;k<n;k++){
            if(A[k]<A[j] and A[k]<A[i])
            continue;
           else if((A[i]+A[j]+A[k])>ans)
            {
                ans=A[i]+A[j]+A[k];
            }
        }
    }
}
 }
    
    return ans;
}
next fix one element and iterarte left and right to get best possible value


best 
int Solution::solve(vector<int> &A) {
 
    int n=A.size();int ans=0;
  //right suffix array

  
vector<int>suffix(n);
 //building right suffix array and to get maximum element on right
  for(int i=n-1;i>=0;i--){
  if(i==n-1)
  suffix[i]=A[i];
  else
  suffix[i]=max(suffix[i+1],A[i]);
  }
  set<int>s;
  for(int i=0;i<n;i++)
  {s.insert(A[i]);   //to get the smaller element just before that
  auto it=s.find(A[i]);
  if(it!=s.begin() and suffix[i]!=A[i])
  ans=max(ans,(*--it)+A[i]+suffix[i]);
}
return ans;}
