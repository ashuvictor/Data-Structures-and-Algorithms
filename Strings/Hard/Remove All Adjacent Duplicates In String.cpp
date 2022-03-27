
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
    st.push(s[0]);
        string ans;
        for(int i=1;i<s.size();i++){
            if(!st.empty() and s[i]==st.top())
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }int c=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};