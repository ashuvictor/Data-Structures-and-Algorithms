Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"

https://leetcode.com/problems/reverse-words-in-a-string-iii/
Java 21 Version
class Solution {
    public String reverseWords(String s) {
        char[] arr = s.toCharArray();
        int n = arr.length;
        int i = 0;

        while (i < n) {
            int start = i;

            // Move to end of word
            while (i < n && arr[i] != ' ')
                i++;

            // Reverse word
            int left = start, right = i - 1;
            while (left < right) {
                char temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                left++;
                right--;
            }

            // Skip spaces
            while (i < n && arr[i] == ' ')
                i++;
        }

        return new String(arr);
    }
}
🔁 C++ → Java Mapping
C++	Java
string mutable	use char[]
swap(s[a], s[b])	manual swap
s[i]	arr[i]
return string	new String(arr)
🧠 Why char[]?

Java String is immutable ❌
So we convert to:

char[] arr = s.toCharArray();

Then modify in-place.

🧪 Example

Input:

"Let's take LeetCode contest"

Output:

"s'teL ekat edoCteeL tsetnoc"
⏱ Complexity

Time: O(n)

Space: O(n) (char array)

⚡ Cleaner Java Version (Using split)

Not optimal but readable:

class Solution {
    public String reverseWords(String s) {
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();

        for (String word : words) {
            sb.append(new StringBuilder(word).reverse()).append(" ");
        }

        return sb.toString().trim();
    }
}
