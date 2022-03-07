Given an input stream of A of n characters consisting only of lower case alphabets.
The task is to find the first non repeating character, each time a character is inserted to the stream. 
If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    deque<char>dq;
		    string ans="";
		    int n=A.size();
		    int flag[26]={0};
		    for(int i=0;i<n;i++){
		        dq.push_back(A[i]);
		        flag[A[i]-'a']++;
		        while(!dq.empty() and flag[dq.front()-'a']>1)
		        {dq.pop_front();
		        }
		        if(dq.empty())
		        ans+="#";
		        else
		        ans+=dq.front();
		    }
		    return ans;
		}

};