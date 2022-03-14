 https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1#
 int prec( char c )

    {

        if(c == '^')

        return 3;

        else if(c == '*' || c == '/')

        return 2;

        else if(c == '+' || c == '-')

        return 1;

        else

        return -1;

    }

    string infixToPostfix(string s)

    {

        // Your code here

        stack<char> st;

        st.push('N');

        int l = s.length();

        string ns;

    

        for(int i = 0; i < l; i++)

        {

            if((s[i] >= 'a' && s[i] <= 'z')|| (s[i] >= 'A' && s[i] <= 'Z'))

                ns+=s[i];

                

            else if(s[i] == '(')

                st.push('(');

        

            else if(s[i] == ')')

            {

                while(st.top() != 'N' && st.top() != '(')

                {

                    ns+=st.top();

                    st.pop();

                }

                if(st.top() == '(')

                    st.pop();

            }

        

            else

            {

                while(st.top() != 'N' && prec(s[i]) <= prec(st.top()))

                {

                    ns += st.top();

                    st.pop();

                }

                st.push(s[i]);

            }

        }

        

        while(st.top() != 'N')

        {

            ns += st.top();

            st.pop();

        }

        return ns;

    }