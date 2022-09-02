Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary words.

Note: From the dictionary B each word can be taken any number of times and in any order.
Example 1:

Input:
n = 12
B = { "i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango" }
A = "ilike"
Output:
1
Explanation:
The string can be segmented as "i like".

bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.size();
    set<string> d(wordDict.begin(), wordDict.end());
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            string substr = s.substr(j, i - j);
            dp[i] = dp[j] && d.count(substr);
            if (dp[i])
                break;
        }
    }
    return dp[n];
}
u/ recursion //O(2^n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto word:wordDict){
            st.insert(word);
        }
        return f(0,s, st);
    }
    int f(int i, string& s, set<string>& st){
        int n= s.size();
        if(i==n)
            return 1;
        string temp;
        for(int j=i; j<n; j++){
            temp += s[j];
            if(st.find(temp)!= st.end()){
                if(f(j+1, s, st))
                    return 1;
            }
        }
        return 0;
    }
}; 

// memoization  time->O(n)  space->O(n)+O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto word:wordDict){
            st.insert(word);
        }
        int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s, st,dp);
    }
    int f(int i, string& s, set<string>& st, vector<int>& dp){
        int n= s.size();
        if(i==n)
            return 1;
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i; j<n; j++){
            temp += s[j];
            if(st.find(temp)!= st.end()){
                if(f(j+1, s, st,dp))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
}; 
