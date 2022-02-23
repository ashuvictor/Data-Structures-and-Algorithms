class Solution
{
public:
	string toBinary(int n)
	{
		// Write your code here...
  string binary;int len=32;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary += (n & i) ? "1" : "0";
    }
 
    return binary;
	}
};
void toBinary(int N)
{
    // your code here
    int binary[32];
    int i=0;
    while(N!=0)
    {
        binary[i]=N%2;
        N=N>>1;
        i++;
    }
   for(int j = i - 1 ; j >= 0 ; j--)
   {
       printf("%d" , binary[j]);
   }
        
}
