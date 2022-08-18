
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"


class Solution {
public:
    int minLen(vector<string>strs){
        int ans=strs[0].length();
        for(int i=1;i<strs.size();i++)
        {
            if(ans<strs[i].length())
                ans=strs[i].length();
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int sz=minLen(strs);
        string result="";
        char current;
        for(int i=0;i<sz;i++){
            current=strs[0][i];
            for(int j=0;j<strs.size();j++)
            {
                if(current!=strs[j][i])
                    return result;
            }
        result.push_back(current);}
        return result;
    }
};