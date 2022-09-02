Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1/
https://leetcode.com/problems/minimum-window-substring/


acquire till the time you get the  and when you get all then start releasing till match count doesnt disturb





string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int n = s.size();
        for(char i : t) mp[i]++;    // mantain count of each char of t
        int i = 0, j = 0, mn = INT_MAX;
        
        int count = mp.size();
        string ans = "";
        
        while(j < n){
            if(mp.find(s[j]) != mp.end()) {     // if that char is found reduce it's count
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;     //if that char's count got to 0 then we've completely found one char so reduce var count
            }
            
            while(count == 0){
                if(mn > j-i+1){
                    mn = min(mn, j-i+1);     // change min as found a valid canditate for ans
                    ans = s.substr(i,j-i+1);
                }
                if(mp.find(s[i]) != mp.end()){    //optimize further and slide the window
                    mp[s[i]]++;
                    if(mp[s[i]]==1) count++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }



    GFG
    class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        set<char>st;
        for(char ch:str)
        st.insert(ch);
         unordered_map<char,int>m;
        int i=0,j=0;
        int ans=str.size();
        while(j<str.size())
        {
            m[str[j]]++;
            if(m.size()==st.size())
            {
                while(m[str[i]]>1)
                {
                    m[str[i]]--;
                    i++;
                }
                ans=min(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};