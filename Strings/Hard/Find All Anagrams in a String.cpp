https://leetcode.com/problems/find-all-anagrams-in-a-string/
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

pproach 1: Brute Force (Finding all substrings of size (p) and cheacking if it is anagram or not)
Status: TLE
class Solution {
public:
    bool isAnagram(string s,string t){
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>idx;
        int n=s.size();
        int m=p.size();
        for(int i=0;i<=n-m;i++){
            string temp=s.substr(i,m);
            if(isAnagram(temp,p))
                idx.push_back(i);
        }
        return idx;
    }
};




class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    vector<int>ans;
        if(p.size()>s.size())
            return ans;
        vector<int>a(26,0);
        vector<int>b(26,0);
        for(int i=0;i<p.size();i++){
            a[p[i]-'a']++;
            b[s[i]-'a']++;
        }
        for(int i=p.size();i<s.size();i++){
            if(a==b)
                ans.push_back(i-p.size());
            b[s[i-p.size()]-'a']--;
            b[s[i]-'a']++;
        }
        if(a==b)
            ans.push_back(s.size()-p.size());
        return ans;
    }
};