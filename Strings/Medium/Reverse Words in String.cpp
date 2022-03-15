Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"

https://leetcode.com/problems/reverse-words-in-a-string-iii/
class Solution {
public:
    string reverseWords(string s) {
int length=s.length();
        int i=0;
        while(i<length){
            int start=i;
            while(i<length and s[i]!=' ')
                i++;
            int left=start,right=i-1;
            while(left<right)
            {
                swap(s[left],s[right]);
                left++;
                right--;
            }
            while(i<length and s[i]==' ')
                i++;
            
        }
        return s;
    }
};