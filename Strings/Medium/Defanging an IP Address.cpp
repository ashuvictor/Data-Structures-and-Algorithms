https://leetcode.com/problems/defanging-an-ip-address/

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

class Solution {
    public String defangIPaddr(String address) {
        String defanged = "[.]";
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < address.length(); i++) {
            if (address.charAt(i) == '.') {
                ans.append(defanged);
            } else {
                ans.append(address.charAt(i));
            }
        }

        return ans.toString();
    }
}



class Solution {
    public String defangIPaddr(String address) {
        return address.replace(".", "[.]");
    }
}
