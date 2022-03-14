https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long >ans(n);
        stack<long long>st;
        for(int i=n-1;i>=0;i--){
            long long current=arr[i];
            while(!st.empty() and current>st.top())
            st.pop();
            ans[i]=(st.empty())?-1:st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};