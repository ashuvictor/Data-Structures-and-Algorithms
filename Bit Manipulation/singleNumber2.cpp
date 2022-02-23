https://www.interviewbit.com/problems/single-number-ii/
https://leetcode.com/problems/single-number-ii/
//Counting SET-BIT
       class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int check, count, ans = 0;
        for(int i=0; i<=31; i++){
            check = 1<<i, count=0;
            for(auto n : nums) if(n & check) count++;
            if(count%3) ans |= check;
        }
        return ans;
    }
};

          //SORTING
        int n=nums.size();
        if(n<3)
            return nums[0];
        
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1])
            return nums[0];
        int i=1;
        while(i<n)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
            i+=3;
        }
        return nums[n-1];
        */
    }
};