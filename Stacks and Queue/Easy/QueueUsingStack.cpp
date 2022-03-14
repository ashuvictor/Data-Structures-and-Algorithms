void StackQueue :: push(int x)

{

    s1.push(x);

}



//Function to pop an element from queue by using 2 stacks.

int StackQueue :: pop()

{

    if(s1.empty() && s2.empty())

        return -1;

    if(s2.empty())

    {

        while(!s1.empty())

        {

            int temp=s1.top();

            s1.pop();

            s2.push(temp);

        }

    }

    int x=s2.top();

    s2.pop();

    return x;

}