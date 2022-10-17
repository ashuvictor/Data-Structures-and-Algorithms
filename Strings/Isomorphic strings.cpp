
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char,char>mp;
        set<char>st;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])==0 and st.count(t[i])==0)
            {
                mp[s[i]]=t[i];
                
                st.insert(t[i]);
            }            
            else if(mp.count(s[i])==0 and st.count(t[i]))
            {
                return false;
            }
            else if(mp[s[i]]!=t[i])
                return false;
            
        }
        return true;
    }
};
