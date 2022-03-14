C++ Code (Using sliding window algorithm)
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.


Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.
https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1/#
 

int longestKSubstr(string s, int k) {
   // your code here
   int i=0,j=0;
   int result=-1;
   unordered_map<char,int>m;
   while(j<s.size())
   {
       m[s[j]]++;
       if(m.size()<k)  j++;
       else if(m.size()==k)
       {
           result=max(result,j-i+1);
           j++;
       }
       else if(m.size()>k)
       {
           while(m.size()>k)
           {
               m[s[i]]--;
               if(m[s[i]]==0)
               {
                   m.erase(s[i]);
               }
               i++;
           }
           j++;
       }
   }
   return result;
   }