/*
You are given N identical eggs and you have access to a K-floored building from 1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty what the value of f is.

Input:
N = 1, K = 2
Output: 2
Explanation: 
1. Drop the egg from floor 1. If it 
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
   https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
*/
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int t[201][201];
    int solve(int e,int f){
        if(e==1 or f==0 or f==1)
        return f;
        if(t[e][f]!=-1)
        return t[e][f];
        int ans=INT_MAX;
        for(int i=1;i<=f;i++){
            int temp=1+max(solve(e-1,i-1),solve(e,f-i));//if egg breaks then we have to search down that is floor and egg reduce
            ans=min(ans,temp);//if egg does not break f-i floor are left 
        }
        return t[e][f]=ans;// we use the max beacuse we have to find for the worst case
    }
    int eggDrop(int n, int k) 
    { memset(t,-1,sizeof(t));
    return solve(n,k);
        // your code here
    }
};