
https://leetcode.com/problems/capitalize-the-title/

You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by changing the capitalization of each word such that:

If the length of the word is 1 or 2 letters, change all letters to lowercase.
Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
Return the capitalized title.

 

Example 1:

Input: title = "capiTalIze tHe titLe"
Output: "Capitalize The Title"
Explanation:
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.


 class Solution {
public:
    string capitalizeTitle(string title) {
int i=0;
        for(int j=0;j<title.size();j++){
            if(title[j]==' '){
                i=j+1;
            }
            else{
                title[j]=tolower(title[j]);
                if(j-i+1>2)
                    title[i]=toupper(title[i]);
            }
        }
        return title;
        
    }
};