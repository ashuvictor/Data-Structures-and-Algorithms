
https://leetcode.com/problems/permutation-in-string/
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false



 bool checkInclusion(string s1, string s2) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        int l1=s1.size();
        int l2=s2.size();
        if(l1>l2)
            return false;
        int left=0,right=0;
        while(right<l1){
            v1[s1[right]-'a']++;
            v2[s2[right]-'a']++;
            right++;
        }
        right--;
        while(right<l2){
            if(v1==v2)
                return true;
            right++;
            if(right<l2){
                v2[s2[right]-'a']++;
                v2[s2[left]-'a']--;
            }
            left++;
        }
        return false;
    }