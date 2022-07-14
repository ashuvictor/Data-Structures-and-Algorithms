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


unordered_map<string, int> dp;
    
    int solve(string a, vector<string> &b) {
        int sz = a.length();
        
        if (sz == 0) return 1;
        if (dp[a] != 0) return dp[a];
        
        for (int i=1; i<=sz; i++) {
            int f = 0; 
            string ss = a.substr(0, i);
            
            for (int j=0; j<b.size(); j++) {
                
                if (ss.compare(b[j]) == 0) {
                    f = 1;
                    break;
                }
            }
            
        	if (f==1 and solve (a.substr(i, sz-i), b) == 1) 		 return dp[a] = 1;
        }
        
        return dp[a] = -1;
        
    }
    

    int wordBreak(string A, vector<string> &B) {
        //code here
        int x = solve(A, B);
        
        if (x == 1) return 1;
        else return 0;
    }