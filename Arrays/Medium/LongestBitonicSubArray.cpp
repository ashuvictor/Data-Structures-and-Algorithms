/* LONGEST BITONIC SUBARRAY
https://practice.geeksforgeeks.org/problems/maximum-length-bitonic-subarray5730/1/
*/
class Solution{
public:	
	// Function to find length of longest bitonic
	// subarray
	int bitonic(vector<int> arr, int n) {
	   int inc[n];
	   int dec[n];
	   inc[0]=1;
	   dec[n-1]=1;
	   for(int i=1;i<n;i++)
	   inc[i]=(arr[i]>=arr[i-1])?inc[i-1]+1:1;
	   for(int i=n-2;i>=0;i--)
	   dec[i]=(arr[i]>=arr[i+1])?dec[i+1]+1:1;
	   int maxValue=inc[0]+dec[0]-1;
	   for(int i=1;i<n;i++)
	   {
	       if((inc[i]+dec[i]-1)>maxValue)
	       maxValue=inc[i]+dec[i]-1;
	   }
	   return maxValue;
	   
	}
};