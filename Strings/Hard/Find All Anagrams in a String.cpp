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
    bool areAnagram(string str1, string str2)
    {
        sort(str1.begin(), str1.end());
        for (int i=0;i<str1.size();i++)
        {
            if (str1[i]!=str2[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<string> v;
        vector<int> ans;
        string k="";
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<i+p.size() && j<s.size();j++)
            {
                k+=s[j];
            }
            if(k.size()==p.size())
            {
                v.push_back(k);   
            }
            k="";
        }
        sort(p.begin(),p.end());
        for(int i=0;i<v.size();i++)
        {
            if(areAnagram(v[i],p))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
Approach 2: Using Hash table
Status: AC
Credit: Youtube Channel Tech Dose

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int window = p.size();
        int len = s.size();
        if(len < window)
        {
            return ans;
        }
        int left = 0,right = 0;
        while(right < window)
        {
            phash[p[right] - 'a'] += 1;
            hash[s[right] - 'a'] += 1;
            right++;
        }
        right -=1;
        while(right < len)
        {
            if(phash == hash)
            {
                ans.push_back(left);
            }
            right+=1;
            if(right != len)
            {
                hash[s[right] - 'a'] += 1;
            }
            hash[s[left] - 'a'] -=1 ;
            left += 1;
        }
        return ans;
    }
};