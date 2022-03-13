/* NEXT PERMUTATION 
https://leetcode.com/problems/next-permutation/
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz=nums.size();
        int s,k;
        for( k=sz-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0)
            reverse(nums.begin(),nums.end());
        else{
            for(s=sz-1;s>k;s--){
                if(nums[s]>nums[k])
                    break;
            }
            swap(nums[s],nums[k]);
            reverse(nums.begin()+1+k,nums.end());
        }
    }
};