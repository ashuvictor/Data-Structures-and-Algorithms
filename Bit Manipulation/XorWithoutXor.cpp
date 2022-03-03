/*

Given two integers, find their XOR without using the XOR operator.

Input: x = 65, y = 80
Output: 17
Explanation: x in binary is 01000001 and y in binary is 01010000. Their XOR is 00010001, which is 17 in decimal.

*/

class Solution
{
public:
	int findXOR(int x, int y)
	{
		// Write your code here...
		return (x|y)-(x&y);
	}
};
 
The expression (x | y) - (x & y) is equivalent to x ^ y (finding XOR of two numbers x and y). The XOR works by setting the bits which are
 set in either of one of the given numbers (0 ^ 1 = 1, 1 ^ 0 = 1) and finally taking out the common bits present in both numbers (1 ^ 1 = 0).