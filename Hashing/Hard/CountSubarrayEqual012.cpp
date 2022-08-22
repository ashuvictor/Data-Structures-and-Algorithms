/*  COUNT OF SUBARRAY WITH EQUAL 0 ,1,2
Same technique as in longest subarray one-zero and two -one
https://practice.geeksforgeeks.org/problems/equal-0-1-and-23208/1/
*/
class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
    long long int zero=0,one=0,two=0;
    unordered_map<string,int>mp;
    long long int count=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='0')
        {
            zero++;
        }
        else if(str[i]=='1'){
            one++;
        }
        else{
            two++;
        }
        string key=to_string(one-zero)+"#"+to_string(two-one);
        if(one-zero==0 and two-one==0)
        count++;
        if(mp.find(key)!=mp.end())
        count+=mp[key];
        mp[key]++;
    }
    return count;
    }
};