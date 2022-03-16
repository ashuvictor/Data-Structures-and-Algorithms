void copySetBits(unsigned &x, unsigned y,
                 unsigned l, unsigned r)
{
   // l and r must be between 1 to 32
   // (assuming ints are stored using
   //  32 bits)
   if (l < 1 || r > 32)
      return ;
 
   // Traverse in given range
   for (int i=l; i<=r; i++)
   {
       // Find a mask (A number whose
       // only set bit is at i'th position)
       int mask = 1 << (i-1);
 
       // If i'th bit is set in y, set i'th
       // bit in x also.
       if (y & mask)
          x = x | mask;
   }
}

second ways 
making a mask of the given range
int m1=00000001
m1<<(length)=00100000
m1<<(length)-1=0011111
int m1=1;
m1=m1<<(right-left+1);
m1--;
m1=m1<<(left-1);
m1=m1&a;
b=b | m1;
cout<<b;