class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)   //next greater element on left
    {
       vector<int>ans(n);
       ans[0]=1;
       stack<int>st;
       st.push(0);
       for(int i=1;i<n;i++){
           int current=price[i];
           while(!st.empty() and price[st.top()]<=current)
           st.pop();
           ans[i]=st.empty()?(i+1):i-st.top();
           st.push(i);
       }
       return ans;
    }
};