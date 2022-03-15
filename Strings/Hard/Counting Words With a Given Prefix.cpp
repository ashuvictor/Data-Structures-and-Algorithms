https://leetcode.com/problems/counting-words-with-a-given-prefix/

You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0; int sz=pref.size();
        for(auto &x:words){
            string str=x.substr(0,sz);
            if(str==pref)
                ans++;
        }
        return ans;
    }
};