Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.


Example 1:

Input:
N=3,  K=2 
Output: 6
Explanation: 
We have following possible combinations:
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
         if (n == 0)
        return 0;
        if(n == 1)
         return k;
        int modulo=1e9+7;
        long long same=k;
        long long diff=k*(k-1);
        long long total=same+diff;
        for(long long i=3;i<=n;i++){
            same=(diff)%modulo;
            diff=(total*(k-1))%modulo;
            total=(same+diff)%modulo;
            
        }
        return total%modulo;
    }
};