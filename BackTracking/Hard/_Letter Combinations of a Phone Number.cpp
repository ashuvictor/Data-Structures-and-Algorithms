https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
   void solve(string digits,string output,int index,vector<string>&ans,unordered_map<int,string>mp)
   {
       if(index>=digits.size())
       {
           ans.push_back(output);
           return;
       }
       int number=digits[index]-'0';
       string value=mp[number];
       for(int i=0;i<value.length();i++){
           output.push_back(value[i]);
           solve(digits,output,index+1,ans,mp);
           output.pop_back();
       }
   }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)
            return ans;
         unordered_map<int,string>mp;
         mp[2]="abc";

        mp[3]="def";

        mp[4]="ghi";

        mp[5]="jkl";

        mp[6]="mno";

        mp[7]="pqrs";

        mp[8]="tuv";

        mp[9]="wxyz";
        string output;
        int index=0;
        solve(digits,output,index,ans,mp);
        return ans;
    }
};