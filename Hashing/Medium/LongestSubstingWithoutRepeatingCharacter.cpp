Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] lastSeen = new int[256];

        // Initialize with -1
        for (int i = 0; i < 256; i++) lastSeen[i] = -1;

        int left = 0, len = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);

            if (lastSeen[c] != -1) {
                left = Math.max(left, lastSeen[c] + 1);
            }

            lastSeen[c] = right;
            len = Math.max(len, right - left + 1);
        }

        return len;
    }
}


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
