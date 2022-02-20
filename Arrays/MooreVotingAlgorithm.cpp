/* MOORE VOTING ALGORITHM 
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.
 https://leetcode.com/problems/majority-element/
 */
 class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,num=0;
        for(auto x:nums){
            if(cnt==0){
                num=x;
            }
            if(x==num){
                cnt++;
            }
            else
                cnt--;
        }
        return num;
    }
};
/*Given an integer array of size n,
 find all elements that appear more than ⌊ n/3 ⌋ times.
 https://leetcode.com/problems/majority-element-ii/
 */
 class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int sz=nums.size();
        int num1=-1,num2=-1,count1=0,count2=0;
        for(int i=0;i<sz;i++){
            if(nums[i]==num1)
            {
                count1++;
            }
            else if(nums[i]==num2){
                count2++;
            }
            else if(count1==0)
            {
                num1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                num2=nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(auto x:nums){
            if(x==num1)
                count1++;
           else if(x==num2)
                count2++;
        }
        if(count1>sz/3)
            ans.push_back(num1);
        if(count2>sz/3)
            ans.push_back(num2);
        return ans;
    }
};