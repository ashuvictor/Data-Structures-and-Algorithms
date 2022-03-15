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

class Solution {
public:
     string countAndSay(int n) {
        if(n==1)
		return "1";
		 if(n==2)
		return "11";
string s="11";
for(int i=3;i<=n;i++){
	string t="";
	s=s+'&'; // use of delimiter
	int c=1;

	for(int j=1;j<s.length();j++){
		if(s[j]!=s[j-1]){
			t=t+to_string(c);
			t=t+s[j-1];
			c=1;
		}
		else 
		c++;
	}
	s=t;
}
return s;
    }
};