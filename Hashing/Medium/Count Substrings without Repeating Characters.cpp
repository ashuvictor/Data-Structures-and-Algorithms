// C++ program to find the count of
// all unique sub-strings with
// non-repeating characters
Given a string str consisting of lowercase characters, the task is to find the total numbers of unique substrings with non-repeating characters.
Examples: 
 

Input: str = “abba” 
Output: 4 
Explanation: 
There are 4 unique substrings. They are: “a”, “ab”, “b”, “ba”.
import java.util.*;

public class Solution {

    // Function to count all unique distinct character substrings
    public static int distinctSubstring(String P) {
        int N = P.length();
        Set<String> set = new HashSet<>();

        // Iterate over all substrings
        for (int i = 0; i < N; i++) {

            boolean[] freq = new boolean[26];
            StringBuilder s = new StringBuilder();

            for (int j = i; j < N; j++) {
                int pos = P.charAt(j) - 'a';

                // If character already seen → stop
                if (freq[pos]) break;

                freq[pos] = true;

                s.append(P.charAt(j));
                set.add(s.toString());
            }
        }

        return set.size();
    }

    public static void main(String[] args) {
        String S = "abba";
        System.out.println(distinctSubstring(S));
    }
}
\




public static int distinctSubstring(String s) {
    int[] lastSeen = new int[26];
    Arrays.fill(lastSeen, -1);

    int left = 0, result = 0;

    for (int right = 0; right < s.length(); right++) {
        int c = s.charAt(right) - 'a';

        if (lastSeen[c] >= left) {
            left = lastSeen[c] + 1;
        }

        result += right - left + 1;
        lastSeen[c] = right;
    }

    return result;
}