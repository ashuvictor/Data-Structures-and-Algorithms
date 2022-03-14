Given a balanced expression, find if it contains duplicate parenthesis or not. A set of parenthesis are duplicate if the same subexpression is surrounded by multiple parenthesis. 

Examples: 

Below expressions have duplicate parenthesis - 
((a+b)+((c+d)))
The subexpression "c+d" is surrounded by two
pairs of brackets.

(((a+(b)))+(c+d))
The subexpression "a+(b)" is surrounded by two 
pairs of brackets.



//push all the elements if you get a closing bracket pop all the elements until you get  opening bracket 
//if you are doing this then no duplicate brackets 
//if without popping you get opening bracket means duplicacy is there
stack<char>st;
for(int i=0;i<s.size();i++){
  char ch=s[i];
  if(ch==')')
  {
      if(st.top()=='(')
      return true;
      else{
          while(st.top()!='(')
          {st.pop();}st.pop();
          
      }
  }
  else{
      st.push(ch);
  }
}
return false;