//https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int>st;
        for(int i=0;i<S.size();i++){
            if(S[i]>='0' and S[i]<='9')
            st.push(S[i]-'0');
            else{
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                switch(S[i]){
                    case '+' : st.push(y+x);break;
                    case '-' : st.push(y-x);break;
                    case '*' : st.push(y*x);break;
                    case '/' : st.push(y/x);break;
                }
                
            }
        }
        return st.top();
    }
};
//PREFIX EXPRESSION
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePrefix(string S)
    {
        stack<int>st;
        int n=S.size();
        for(int i=n-1;i>=0;i--){
            if(S[i]>='0' and S[i]<='9')
            st.push(S[i]-'0');
            else{
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                switch(S[i]){
                    case '+' : st.push(y+x);break;
                    case '-' : st.push(x-y);break;
                    case '*' : st.push(y*x);break;
                    case '/' : st.push(x/y);break;
                }
                
            }
        }
        return st.top();
    }
};