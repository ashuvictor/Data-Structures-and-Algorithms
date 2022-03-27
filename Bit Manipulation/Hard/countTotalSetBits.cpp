


https://www.interviewbit.com/problems/count-total-set-bits/
Problem Description

Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.

Return the count modulo 109 + 7.



Problem Constraints
1 <= A <= 109



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the ( Total number of set bits in the binary representation of all the numbers from 1 to A )modulo 109 + 7.



Example Input
Input 1:

 A = 3
Input 2:

 A = 1

int Solution::solve(int A) {
    if(A==0)
    return 0;
    long long int p=0,ans=0;int mod=1e9+7;
    while(pow(2,p)<=A) p++;
    p--;
    ans+=p*pow(2,p)/2+(A-pow(2,p)+1)+solve(A-pow(2,p));
    return ans%mod;
}
