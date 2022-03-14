Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1/
https://leetcode.com/problems/minimum-window-substring/


acquire till the time you get the  and when you get all then start releasing till match count doesnt disturb





string minWindow(string s, string t) {
int count =0;int start_idx=-1;
int min_so_far=INT_MAX;
int start=0;int window_size;

    //now making our searing table by array
    int ft[256]={0};//frequency list of t array
    int fs[256]={0};//frequency list of s array
    
    //update frequency of t in ft
    for(int i=0;i<t.length();i++){
        ft[t[i]]++;
    }
    
    //sliding window algorithm
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        fs[ch]++;
        
     //we will check how many characters matched till now in fs and ft
        if(ft[ch]!=0 && fs[ch]<=ft[ch]){
            count++;
        }
        
      //any point if string t length==count i.e all frequency we contain in fs
      //start contraction
        
       if(count==t.length()){
        //start removing from left if the character not present in t string 
        //or frequency is higher than the required frequency
         while(ft[s[start]]==0 || fs[s[start]]>ft[s[start]]){
             fs[s[start]]--;
             start++;
         }
           //note the window size
        window_size=i-start+1;
        if(window_size<min_so_far){
            min_so_far=window_size;
            start_idx=start;
        }
           
      }
        
        
        
    }
    if(start_idx==-1){return "";}
    
    return s.substr(start_idx,min_so_far);
}