/* Palindrome Partioning
https://leetcode.com/problems/palindrome-partitioning/
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
*/
class Solution {
public:
    bool isPal(string s,int low,int high){
        while(low<high){
            if(s[low++]!=s[high--])
                return false;
        }
        return true;
    }
    void solve(int start,string s,vector<string>&temp,vector<vector<string>>&ans)
    {
        if(start==s.size())
        {
            ans.push_back(temp);
        }
        for(int end=start;end<s.size();end++){
            if(isPal(s,start,end)){
                temp.push_back(s.substr(start,end-start+1));
                solve(end+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,temp,ans);
        return ans;
    }
};