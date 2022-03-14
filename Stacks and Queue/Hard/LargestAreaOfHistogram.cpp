Given an array of integers heights representing the histogram's bar
 height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 https://leetcode.com/problems/largest-rectangle-in-histogram/
 class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int leftSmall[n];
        int rightSmall[n];
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i])
                st.pop();
            leftSmall[i]=(st.empty())?0:(st.top()+1);
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i])
                st.pop();
            rightSmall[i]=st.empty()?(n-1):(st.top()-1);
            st.push(i);
        }
        int maxA=0;
        for(int i=0;i<n;i++){
            maxA=max(maxA,heights[i]*(rightSmall[i]-leftSmall[i]+1));
        }
        return maxA;
    }
};

 