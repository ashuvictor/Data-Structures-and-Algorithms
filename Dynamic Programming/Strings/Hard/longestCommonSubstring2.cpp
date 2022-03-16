/*

Given two strings, find the longest string that is a substring of both strings.

Input: X = "ABABC", Y = "BABCA"
Output: "BABC"
Explanation: The longest common substring of strings "ABABC" and "BABCA" is "BABC" having length 4. The other common substrings are "ABC", "A", "AB", "B", "BA", "BC", and "C".
https://techiedelight.com/practice/?problem=LongestCommonSubstring
*/

class Solution
{
public:
	string findLongestCommonSubstring(string X, string Y)
	{
		// Write your code here...
		int maxLen=0;
		int l1=X.length();
		int l2=Y.length();int ending=l1;
		int dp[l1+1][l2+1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=l1;i++)
		{
			for(int j=1;j<=l2;j++){
				if(X[i-1]==Y[j-1])
				{dp[i][j]=dp[i-1][j-1]+1;
				if(dp[i][j]>maxLen)
				{
					maxLen=dp[i][j];
					ending=i;
				}
			}
		}
		}
		return X.substr(ending-maxLen,maxLen);
	}
};

