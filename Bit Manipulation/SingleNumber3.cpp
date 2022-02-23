https://leetcode.com/problems/single-number-iii/
vector<int> singleNumber(vector<int>& nums) {
        unsigned exor = 0;
        
        for(auto v: nums)
            exor ^= v;
        
        unsigned lsb = exor & -exor;
        int a = 0, b = 0;

        for(auto v: nums)
            if(v & lsb)
                a ^= v;
        
        b = a ^ exor;
        
        return {a, b};
    }
    class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 2) {
            return nums;
        }
        
        long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        
        int lsb = res & ~(res-1);
        int x = 0;
        int y = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] & lsb) {
                x ^= nums[i];
            } else {
                y ^= nums[i];
            }
        }

        return vector<int>{x,y};
    }
};