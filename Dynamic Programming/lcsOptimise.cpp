/*

Given two sequences, find the length of the longest common subsequence (LCS) present in it. The LCS is the longest sequence which can be obtained from the first sequence by deleting some items and from the second sequence by deleting other items.

Input: X = "ABCBDAB", Y = "BDCABA"
Output: 4
Explanation: The LCS are "BDAB", "BCAB", and "BCBA", having length 4.

*/

class Solution
{
public:
	int findLCSLength(string X, string Y)
	{
		// Write your code here...
		int l1=X.length();
		int l2=Y.length();
	int curr[l2+1],prev[l2+1];
	for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			if(i==0 or j==0)
			curr[j]=0;
			else{
				if(X[i-1]==Y[j-1])
				curr[j]=prev[j-1]+1;
				else
				curr[j]=max(prev[j],curr[j-1]);
			}
		}
	for(int i=0;i<=l2;i++)
	prev[i]=curr[i];
		
	}
	return curr[l2];
	
	}
};
