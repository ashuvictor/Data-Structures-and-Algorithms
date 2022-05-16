https://leetcode.com/problems/valid-palindrome/
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
class Solution {
public:

    bool isPalindrome(string s) 
    {
        transform(s.begin(), s.end() , s.begin() ,::tolower) ;
        
        string ans = "" ;
        for(char x:s)
        {
            if((x>='a' and x<='z') or (x>='0' and x<='9')) ans+=x;
        }
        
        string ans_org  = ans ;
        reverse(ans.begin() ,ans.end()) ;
        
        return ans==ans_org ;
    }
};