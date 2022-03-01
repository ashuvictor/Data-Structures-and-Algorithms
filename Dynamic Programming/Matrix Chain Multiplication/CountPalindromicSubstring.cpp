/* count palindromic substrings
https://www.youtube.com/watch?v=XmSOWnL6T_I&t=29s
*/
string s;
cin>>s;
int count=0;
int dp[s.size()][s.size()];//rows has the starting point and columns have the ending point
for(int gap=0;gap<s.size();gap++){
// row is i=0, and column is i+gap
for(int i=0,j=gap;j<s.size();i++,j++){   // all start at the first row but at end the last column
if(gap==0)
{
    dp[i][j]=true;count++;
}
else if(gap==1){
    if(s[i]==s[j])//palindrome with 2 characters
        dp[i][j]=true,count++;
        else
        dp[i][j]=false;
}
else{
    if(s[i]==s[j] and dp[i+1][j-1]==true) //extreme character are equal and the inner part is palindrome
    {
        dp[i][j]=true;count++;
    }
    else
    dp[i][j]=false;
}
}
return ans;
}
