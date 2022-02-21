/* DUPLICATE NUMBER IN ARRAY 
https://leetcode.com/problems/find-the-duplicate-number/
https://www.interviewbit.com/problems/find-duplicate-in-array/
*/
 class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums.size();
        for(int i=0;i<s;i++){
            if(nums[abs(nums[i])-1]>=0)
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        else
            return abs(nums[i]);}
    return -1;}
};
int Solution::repeatedNumber(const vector<int> &A) {
    int slow=A[0];
    int fast=A[0];
    do{
        slow=A[slow];
        fast=A[A[fast]];
    }while(slow!=fast);
     fast=A[0];
    while(slow!=fast){
        slow=A[slow];
        fast=A[fast];
    }
    return slow;
}
