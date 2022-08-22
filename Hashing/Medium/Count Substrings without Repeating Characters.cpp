// C++ program to find the count of
// all unique sub-strings with
// non-repeating characters
Given a string str consisting of lowercase characters, the task is to find the total numbers of unique substrings with non-repeating characters.
Examples: 
 

Input: str = “abba” 
Output: 4 
Explanation: 
There are 4 unique substrings. They are: “a”, “ab”, “b”, “ba”.
#include <bits/stdc++.h>
using namespace std;

// Function to count all unique
// distinct character substrings
int distinctSubstring(string& P, int N)
{
	// Hashmap to store all substrings
	unordered_set<string> S;

	// Iterate over all the substrings
	for (int i = 0; i < N; ++i) {

		// Boolean array to maintain all
		// characters encountered so far
		vector<bool> freq(26, false);

		// Variable to maintain the
		// substring till current position
		string s;

		for (int j = i; j < N; ++j) {

			// Get the position of the
			// character in the string
			int pos = P[j] - 'a';

			// Check if the character is
			// encountred
			if (freq[pos] == true)
				break;

			freq[pos] = true;

			// Add the current character
			// to the substring
			s += P[j];

			// Insert substring in Hashmap
			S.insert(s);
		}
	}

	return S.size();
}

// Driver code
int main()
{
	string S = "abba";
	int N = S.length();

	cout << distinctSubstring(S, N);

	return 0;
}
