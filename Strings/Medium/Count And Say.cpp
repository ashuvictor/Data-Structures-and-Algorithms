https://leetcode.com/problems/count-and-say/
he count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string "3322251":

nput: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"



string solve(string s){
    int n = s.size();
    int i = 0;
    int j = 0;
    int cnt = 0;
    string ans = "";
    while(i<n){
        j = i;
        cnt = 1;
        while(i<n and s[i]==s[i+1]){
            i++;
            cnt++;
        }
        ans += (cnt+'0');
        ans += s[j];    
        i++;
    }
    return ans;
}

string countAndSay(int n) {
    string s = "1";
    n--;
    while(n--){
        s = solve(s);
    }
    return s;
}


string countAndSay(int n) {
        if(n==1)
            return "1";
        string s=countAndSay(n-1);
        int k=1;
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=s[i+1])
            {
                ans+= (k+'0');
                ans+=s[i];
                k=0;
            }
            k++;
        }
        return ans;
    }