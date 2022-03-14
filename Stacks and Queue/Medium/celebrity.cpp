https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++)
        st.push(i);
        while(st.size()>=2){
            int first=st.top();
            st.pop();
            int second=st.top();
            st.pop();
            if(M[first][second]==0)
            st.push(first);
            else
            st.push(second);
        }
        int celebrity=st.top();
        st.pop();
        for(int i=0;i<n;i++){
            if(i!=celebrity){
                if(M[i][celebrity]==0 or M[celebrity][i]==1)
                return -1;
            }
        }
        return celebrity;
    }
};