

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 

Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int mask=1<<i;
            if((mask&x) !=(mask&y))
                ans++;
            
        }
        return ans;
    }
};



https://leetcode.com/problems/total-hamming-distance/

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 

Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();int ans=0;
        for(int i=0;i<32;i++){
            int count1=0,count0=0;
         for(int j=0;j<n;j++){
             if(((1<<i) &nums[j]) ==0)
                 count0++;
             else
                 count1++;
         }
            ans+=count1*count0;
        }
        return ans;
    }
};
https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/

int Solution::hammingDistance(const vector<int> &A) {
      int n=A.size();long long ans=0;int mod=1e9+7;
        for(int i=0;i<32;i++){
           long long count1=0,count0=0;
         for(int j=0;j<n;j++){
             if(((1<<i) &A[j]) ==0)
                 count0++;
             else
                 count1++;
         }
            ans+=(count1*count0*2)%mod;
        }
        return ans%mod;
    
}
