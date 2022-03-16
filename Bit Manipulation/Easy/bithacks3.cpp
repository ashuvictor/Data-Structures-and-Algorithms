How to unset the rightmost set bit of a number?
class Solution
{
public:
	int unsetRightmostSetBit(int n)
	{
		// Write your code here...
		return n&(n-1);
	}
};

int positionOfRightmostSetBit(int n)//best
{
    // if the number is odd, return 1
    if (n & 1) {
        return 1;
    }
 
    return log2(n & -n) + 1;
}
//not for negative
int PositionRightmostSetbit(int n)
{
  int p=1;
   
  // Iterate till number>0
  while(n > 0)
  {
     
    // Checking if last bit is set
    if(n&1){
      return p;
    }
     
    // Increment position and right shift number
    p++;
    n=n>>1;
  }
   
  // set bit not found.
  return -1;
}
unsigned findParity(unsigned n)
{
    bool parity = false;
 
    // run till `n` becomes 0
    while (n)
    {
        // invert the parity flag
        if (n & 1) {
            parity = !parity;
        }
 
        // right shift `n` by 1 (divide by 2)
        n = n >> 1;
    }
 
    return parity;
}
//best
unsigned findParity(unsigned n)
{
    bool parity = false;
 
    // run till `n` becomes 0
    while (n)
    {
        // invert the parity flag
        parity = !parity;
 
        // turn off the rightmost set bit
        n = n & (n - 1);
    }
 
    return parity;
}
