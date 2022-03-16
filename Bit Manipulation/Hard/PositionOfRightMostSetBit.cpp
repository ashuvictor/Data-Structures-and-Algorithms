/*

Given an integer an N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
Note: If there is no set bit in the integer N, then return 0 from the function. 
*/
class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
       return log2(n&(-n))+1;
    }
};

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