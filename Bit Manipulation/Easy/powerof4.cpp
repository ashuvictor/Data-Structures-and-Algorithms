/*
power of 4
https://leetcode.com/problems/power-of-four/
*/
The given number n is a power of 4 if it is a power of 2 and its only set bit is present at even position (0, 2, 4, …).

(0xAAAAAAAA)16 = (10101010101010101010101010101010)2
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0 and !(n&(n-1)) and !(n&10101010101010101010101010101010) )
        return true;   //even position will only be set
    else
    return false;
    }
};


public:
    bool isPowerOfFour(int n) {
        
        if(n<=0)
            return false;
        long long digits=floor(log2(n))+1;
        if((digits%2!=0)&&((n&(n-1))==0))
            return true;
        return false;
        
    }
};
Logic:
The power of 4 always have odd length when converted to binary and have exactly 1 set bit

So we can find the digits of number in binary in constant time using this floor(log2(n))+1;

We can find whether it has a set bit using this n&(n-1)==0
Combining these 2 gives our solution in contant time.


class Solution {
public:
    bool isPowerOfFour(int n) {
      
        if(n>0 and !(n&(n-1)) and (n%3==1))
        return true;   //even position will only be set
    else
    return false;
    }
};