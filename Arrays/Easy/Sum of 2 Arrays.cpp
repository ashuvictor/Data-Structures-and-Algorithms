

You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.
Note:
1. The length of each array is greater than zero.

2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.

3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.
Input Format:
The first line of the input contains an integer T, denoting the number of test cases.

The first line of each test case contains two space-separated integers 'N' and 'M', denoting the size of the two arrays.

The second line of each test case contains 'N' space-separated integers denoting the elements of the first array.

The third line of each test case contains 'M' space-separated integers denoting the elements of the second array.
Output Format:
The only line of output of each test case contains space-separated digits which correspond to the sum of the two numbers 'A' and 'B'.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10^2
1 <= N, M <= 10^4
0 <= A[i], B[i] <= 9

Time Limit: 1 sec
Sample Input 1:
2
4 1 
1 2 3 4
6
3 2
1 2 3
9 9



vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	int i=n-1;
	int j=m-1;int carry=0;
	vector<int>ans;
	while(i>=0 and j>=0)
	{
		int val1=a[i];
		int val2=b[j];
		int sum=val1+val2+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;j--;
	}
	while(i>=0)
	{
		int sum=a[i]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
		i--;
	}
	while(j>=0)
	{
		int sum=b[j]+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);j--;
	}
	while(carry!=0)
	{
		int sum=carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}