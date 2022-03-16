Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.



Given two strings A and B of the same length, determine if B is a scrambled string of S.



Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= len(A), len(B) <= 50
Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1
    bool solve(string a,string b){
    if(a==b)
    return true;
    for(int i=0;i<a.size()-1;i++){
        string s1=a.substr(0,i+1);
        string s2=a.substr(i+1);
        string s3=b.substr(0,i+1);
        string s4=b.substr(i+1);
        string s5=b.substr(0,a.size()-1-i);
        string s6=b.substr(a.size()-1-i);
        if((solve(s1,s3) and solve(s2,s4)) or (solve(s1,s6) and solve(s2,s5)) )
        return true;
    }
    return false;
}
int Solution::isScramble(const string A, const string B) {

    return solve(A,B);
}

https://leetcode.com/problems/scramble-string/

map<pair<string,string>,bool>dp;
bool solve(string a,string b){
    if(a==b)
    return true;
    if(dp.count({a,b}))
    return dp[{a,b}];
    for(int i=0;i<a.size()-1;i++){
        string s1=a.substr(0,i+1);
        string s2=a.substr(i+1);
        string s3=b.substr(0,i+1);
        string s4=b.substr(i+1);
        string s5=b.substr(0,a.size()-1-i);
        string s6=b.substr(a.size()-1-i);
        if((solve(s1,s3) and solve(s2,s4)) or (solve(s1,s6) and solve(s2,s5)) )
        return dp[{a,b}]=true;
    }
    return dp[{a,b}]=false;
}
int Solution::isScramble(const string A, const string B) {

    return solve(A,B);
}

class Solution {
public:
    unordered_map<string,bool>dp;
    bool solve(string a ,string b,int n){
        if(a==b)
            return dp[a+"#"+b]=true;
        else if(a.length()==1)
            return false;
        else if(dp.find(a+"#"+b)!=dp.end())
            return dp[a+"#"+b];
        for(int k=1;k<=n-1;k++){
            bool cond1=solve(a.substr(0,k),b.substr(n-k),k) && solve(a.substr(k,n-k),b.substr(0,n-k),n-k);
            bool cond2=solve(a.substr(0,k),b.substr(0,k),k) and solve(a.substr(k,n-k),b.substr(k,n-k),n-k);
            if(cond1 or cond2)
                 return dp[a+"#"+b]=true;
        }
        return dp[a+"#"+b]=false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        int n=s1.length();
        return solve(s1,s2,n);
    }
};