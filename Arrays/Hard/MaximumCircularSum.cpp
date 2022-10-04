/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and 
the previous element of nums[i] is nums[(i - 1 + n) % n].

https://leetcode.com/problems/maximum-sum-circular-subarray/ */
int maximum(vector &nums){
int maxi=INT_MIN;
int sum=0;
for(int i=0;i<nums.size();i++){
sum += nums[i];
maxi=max(maxi,sum);
if(sum<0){
sum=0;
}
}
return maxi;
}
int minimum(vector &nums){
int mini=INT_MAX;
int sum=0;
for(int i=0;i<nums.size();i++){
sum += nums[i];
mini=min(mini,sum);
if(sum>0){
sum=0;
}
}
return mini;
}
int maxSubarraySumCircular(vector& nums) {
//finding maximum subarray sum using kadanes algo
long long int maxi=maximum(nums);
//finding minimum subarray sum using kadanes algo
long long int mini=minimum(nums);

    int flag=0;
    long long int sum = 0;
    for(int i=0;i<nums.size();i++){
	//check for positive number
        if(nums[i]>0) flag=1;
        sum += nums[i];
    }
	//if all element of array are negative then return maximum negative element
    if(flag==0) return *max_element(nums.begin(),nums.end());
    
    return max(maxi,sum-mini);
}








class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int maxs=INT_MIN,mins=INT_MAX,curr1=0,curr2=0,total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            curr1+=nums[i];
            maxs=max(curr1,maxs);
        curr1=max(curr1,0);
            curr2+=nums[i];
            mins=min(curr2,mins);
            curr2=min(curr2,0);
        }
        return maxs<0?maxs:max(maxs,total-mins);
        
    }
};