/*
Maximum difference of zeros and ones in binary string
https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1
*/
class Solution{
public:	
	int maxSubstring(string S)
	{
	    int sum=0,maxi=INT_MIN;
	    for(auto x:S){
	        if(x=='0')
	        sum+=1;
	        else
	        sum-=1;
	        maxi=max(sum,maxi);
	        if(sum<0)
	        sum=0;
	    }
	    return maxi;
	}
};