https://leetcode.com/problems/permutation-in-string/

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

class Solution {
    private:
    bool check(int a[26],int b[26])
    {
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int count[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            count[index]++;
        }
        //traverse the s2 string in window of size of s1
        int i=0;
        int windowSize=s1.length();
        int count2[26]={0};
        while(i<windowSize and i<s2.length())  //running for 1st window
        {
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }
        if(check(count,count2))
            return true;
        while(i<s2.length())
        {
            int index=s2[i]-'a';
            count2[index]++;
            char oldchar=s2[i-windowSize];
            index=oldchar-'a';
            count2[index]--;
            if(check(count,count2))
            return true;i++;
        }
        return false;
        
    }
};
