/* Max Consecutive ones
https://leetcode.com/problems/max-consecutive-ones/
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0;
        int maxi=0;
        for(auto x:nums){
            if(x==1)
                cnt++;
            else
                cnt=0;
            maxi=max(cnt,maxi);
        }
        return maxi;
    }
};
