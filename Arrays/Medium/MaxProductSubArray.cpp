/* MAX PRODUCT SUBARRAY
https://leetcode.com/problems/maximum-product-subarray/
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp=nums[0];
        int minp=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(maxp,minp);
            minp=min(minp*nums[i],nums[i]);
            maxp=max(maxp*nums[i],nums[i]);
            ans=max(maxp,ans);
        }
        return ans;
    }
};
Appraoch :
Step 1: Traverse the array from Left -> Right.
Step 2: Traverse the array from Right -> Left.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=INT_MIN;
        int prod=1;

        
        for(int i=0;i<nums.size();i++){
            prod=prod*nums[i];
            ans=max(ans,prod);
            
            if(prod==0) prod=1;
        }
        
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod=prod*nums[i];
            ans=max(prod,ans);
            
            if(prod==0) prod=1;
        }
        return ans;
    }
};