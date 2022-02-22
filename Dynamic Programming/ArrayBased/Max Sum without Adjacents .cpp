/*
Max Sum without Adjacents 
https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1/
*/
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	int inc=arr[0];
	int exc=0;
	for(int i=1;i<n;i++)
	{int ninc=exc+arr[i];
	int nexc=max(inc,exc);
	inc=ninc;
	exc=nexc;}
	
return	max(inc,exc);}
};