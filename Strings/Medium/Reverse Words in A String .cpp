




https://leetcode.com/problems/reverse-words-in-a-string/
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

class Solution {
public:
    string reverseWords(string s) {
	
	//we make an answer string, that we have to return
        string ans = "";
		
	//variable for traversing the input string
        int i = 0;
	
	//here we are traversing the input string
        while(i<s.size()){
		//this is the string to store the individual words
            string w;
			//when the spaces occur keep on going further
            while(s[i] == ' '){
                i++;
            }
            
			//as we detect a char we start putting into our w string for storing the word
			//this will keep going on until we detect a space
            while(i<s.size() and s[i]!=' '){
                w.push_back(s[i]);
                i++;
            }
			
			// i was stopped on the sight of space so now time to increment i from the current space index
			//this can be neglected as well because we are taking care of the spaces before the starting of the loop
            i++;
            
			//if the word is empty then do nothing, otherwise attatch it to the front of actual ans string with a space
            if(w.empty() == false){
                ans = w + " " + ans;
            }
        }
        
		//this is a pop to pop the space at the end of the ans, because we are inserting w + space + ans
		//so when the ans was empty then space was inserted before the word so we need to take care of it.
        ans.pop_back();
        return ans;
    }
};