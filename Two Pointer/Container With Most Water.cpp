

https://leetcode.com/problems/container-with-most-water/
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;int ans=0;
        while(left<right){
            int left_h=height[left];
            int right_h=height[right];
           int min_h=min(left_h,right_h);
            ans=max(ans,min_h*(right-left));
            if(left_h<right_h)
                left++;
            else
                right--;
        }
        return ans;
    }
};