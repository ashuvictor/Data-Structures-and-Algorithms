Binary exponentiation (also known as exponentiation by squaring) is a trick which allows to calculate  using only  multiplications


long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
Input Format :
The first line of input contains a single integer 'T', representing the number of test cases. 

The first line of each test contains three space-separated integers 'X', 'N', and 'M'.
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int  res=1;
	while(n>0){
		if(n&1)
		{
			res=(1ll* (res)%m*(x)%m)%m;
		}
		x=(1ll * (x)%m*(x)%m)%m;
		n=n>>1;
		
	}
	return res;
}