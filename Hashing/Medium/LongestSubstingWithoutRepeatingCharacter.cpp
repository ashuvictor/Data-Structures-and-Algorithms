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


#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.size(); ++right) {
        // If character is already in the set, move the left pointer
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            ++left;
        }
        // Add the current character to the set
        charSet.insert(s[right]);
        // Update the maximum length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";

    cout << "Example 1: " << lengthOfLongestSubstring(s1) << endl; // Output: 3
    cout << "Example 2: " << lengthOfLongestSubstring(s2) << endl; // Output: 1
    cout << "Example 3: " << lengthOfLongestSubstring(s3) << endl; // Output: 3

    return 0;
}
