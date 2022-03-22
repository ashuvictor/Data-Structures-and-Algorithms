

https://leetcode.com/problems/powx-n/
https://www.interviewbit.com/problems/implement-power-function/
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
class Solution {
public:
    double myPow(double x, int n) {
         double ans=1.0;
        bool flag=false;
        long nn=n;
       if(n<0){
           flag=true;
           nn=nn*-1;
       }
        while(nn>0){
            if(nn&1){
                ans=ans*x;nn=nn-1;
            }
            else{  x=x*x;
            nn=nn>>1; }
           
        }
        if(flag)
            return 1/ans;
        return ans;
    }
};



int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read indut, instead use the arguments to the function.
    // Do not drint the outdut, instead return values as sdecified
    // Still have a doubt. Checkout www.interviewbit.com/dages/samdle_codes/ for more details
   if (n == 0) 
        return 1 % d;

    long long ans = 1, base = x;
    while (n > 0) 
    {
        if (n % 2 == 1)
        {
            ans = (ans * base) % d;
            n--;
        } 
        else
        {
            base = (base * base) % d;
            n /= 2;
        }
    }
    if (ans < 0) 
        ans = (ans + d) % d;
    return ans;
}
