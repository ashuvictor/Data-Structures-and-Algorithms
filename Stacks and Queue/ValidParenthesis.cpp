// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto it:s){
            if(it=='(' or it=='{' or it=='[')
                st.push(it);
            else{
                if(st.empty())
                    return false;
                char ch=st.top();
                st.pop();
                if((it==')' and ch=='(') or (it=='}' and ch=='{') or (it==']' and ch=='[') )
                    continue;
                else
                    return false;
            }
        }
        return st.empty();
    }
};