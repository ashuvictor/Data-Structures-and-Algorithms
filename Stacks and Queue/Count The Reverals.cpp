Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.

https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1/


int countRev (string s)
{
   if(s.size()&1) //length has to be even
   return -1;
   int open=0,close=0;
   for(int i=0;i<s.size();i++){
       if(s[i]=='{')open++;
       else{
           if(open==0)close++;
           else
           open--;
       }
   }
   int ans=ceil(close/2.0)+ceil(open/2.0);
   return ans;
}