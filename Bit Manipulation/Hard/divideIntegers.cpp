https://leetcode.com/problems/divide-two-integers/
https://www.interviewbit.com/problems/divide-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a=dividend,b=divisor;
        int sign=0;
        if((a>0 and b<0) or(a<0 and b>0))
            sign=1;
        if(a<0)
            a=-a;
        if(b<0)
            b=-b;
        long long int ans=0,temp=0;
        for(int i=31;i>=0;i--){
            if(temp+(b<<i)<=a)
            {
                temp+=b<<i;
                ans+=1ll<<i;
            }
        }
        if(sign)
            ans=-ans;
        if(ans>INT_MAX or ans<INT_MIN)
            return INT_MAX;
        return ans;
        
    }
};