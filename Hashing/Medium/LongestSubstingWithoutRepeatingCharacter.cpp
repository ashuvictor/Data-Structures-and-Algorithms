Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);
        int n=s.size();
        int left=0,right=0,len=0;
        while(right<n){
            if(mpp[s[right]]!=-1)
                left=max(mpp[s[right]]+1,left);
            mpp[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;
    }
};