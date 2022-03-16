Turn off k’th bit in a number
#include <iostream>
#include <bitset>
using namespace std;
 
// Function to turn off k'th bit in `n`
int turnOffKthBit(int n, int k) {
    return n & ~(1 << (k - 1));
}
 
int main()
{
    int n = 20;
    int k = 3;
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    cout << "Turning k'th bit off\n";
    n = turnOffKthBit(n, k);
    cout << n << " in binary is " << bitset<8>(n) << endl;
 
    return 0;
}
Turn on k’th bit in a number
int turnOnKthBit(int n, int k) {
    return n | (1 << (k - 1));
}
Check if k’th bit is set for a number

class Solution
{
public:
	bool isKthBitSet(int n, int k)
	{
		// Write your code here...
		return (n&(1<<(k-1)))!=0;
	}
};
Toggle the k’th bit

class Solution
{
public:
	int toggleKthBit(int n, int k)
	{
		// Write your code here...
		return n^(1<<(k-1));
	}
};

 