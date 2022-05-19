https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1

Given a string S delete the characters which are appearing more than once consecutively.

Example 1:

Input:
S = aabb
Output:  ab 
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
Similiar explanation for b at
4th position.


class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
string str="";
str.push_back(S[0]);
for(int i=1;i<S.length();i++){
    if(str.back()!=str[i]){
        str.push_back(S[i]);
    }
}
return str;
        
    }
    
};