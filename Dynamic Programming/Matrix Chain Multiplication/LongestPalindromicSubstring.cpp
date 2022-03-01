 /*LONGEST PALINDROMIC SUBSTRING
 https://www.youtube.com/watch?v=WpYHNHofwjc&t=31s
 */
 int ans=0;
 bool dp[s.size()][s.size()];
 for(int gap=0;gap<s.size();gap++){
     for(int i=0,j=gap;j<s.size();i++,j++){
         if(gap==0)
         {
           dp[i][j]=true;
         }
         else if(gap==1){
            if(s[i]==s[j])
            dp[i][j]=true;
            else
            dp[i][j]=false;
         }
         else
         { if(s[i]==s[j] and dp[i+1][j-1]==true)
         {
           dp[i][j]=true;
         }
         else{ 
                 dp[i][j]=false;

         }

         }
         if(dp[i][j])
         ans=gap+1;
     }
 }