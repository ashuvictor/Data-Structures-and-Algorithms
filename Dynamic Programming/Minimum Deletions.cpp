/* Minimum deletions 
Given a string of S as input. Your task is to write a program to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: S = "aebcbda"
Output: 2
Explanation: Remove characters 'e' 
and 'd'.
*/
class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
       // code here
       string t=string(s.rbegin(),s.rend());
       int dp[s.length()+1][s.length()+1];
       for(int i=0;i<s.length()+1;i++){
           dp[i][0]=0;
       }
       for(int i=1;i<s.length()+1;i++){
           dp[0][i]=0;
       }
       for(int i=1;i<s.length()+1;i++){
           for(int j=1;j<s.length()+1;j++){
               if(s[i-1]==t[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
       return s.length()-dp[s.length()][s.length()];
   } 
};