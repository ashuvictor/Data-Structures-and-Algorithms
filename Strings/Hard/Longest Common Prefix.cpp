
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		bool f = false;
		int i;
		for(i=0; i < strs[0].length();i++)
		{
			for(int k=1; k < strs.size(); k++)
			{
				if(i == strs[k].length() or strs[k][i] != strs[0][i]) f = true;
			}
			if(f) break;
		}
		string s = "";
		for(int k = 0 ;k < i; k++) s += strs[0][k];
		return s;

	}
};


class Solution {
public:
string longestCommonPrefix(vector& strs) {
sort(strs.begin(), strs.end());
string res = strs.at(0);
int len = res.length();
for(int i = 1; i < strs.size(); i++){
while(res.substr(0, len) != strs[i].substr(0, len))
len--;
if(len < 0)
return "";
res = res.substr(0, len);
}
return res;
}
};