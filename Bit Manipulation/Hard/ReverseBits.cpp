/*
Problem Description

Reverse the bits of an 32 bit unsigned integer A.



Problem Constraints
0 <= A <= 232
https://www.interviewbit.com/problems/reverse-bits/
https://leetcode.com/problems/reverse-bits/
*/

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    unsigned int ans=0;
    for(int i=31;i>=0;i--){
        if(A&(1<<i))  // we check if the current bit is set or not 
        {
            int mask=1<<(31-i);
            ans=ans | mask;
        }
    }
    return ans;
}
