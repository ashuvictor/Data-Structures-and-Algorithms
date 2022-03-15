https://leetcode.com/problems/defanging-an-ip-address/

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

class Solution {
public:
    string defangIPaddr(string address) {
        string defanged="[.]";
        int c=1;string ans="";
        for(int i=0;i<address.size();i++){
            if(address[i]=='.' and c<=3)
            {
                ans=ans+defanged;c++;
            }
            else{
                ans=ans+address[i];   
            }
        }
        return ans;
    }
};