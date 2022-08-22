Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

Example 1 :

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

one number should have remainder x and other as k-x
k/2->even frequency
https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1/
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int rem=nums[i]%k;
            mp[rem]++;
        }
        for(int i=0;i<nums.size();i++){
            int rem=nums[i]%k;
            if(rem==0)   //number is divisible then frequency is even
            {
                if(mp[rem]%2==1)
                return false;
            }
            else if(rem*2==k)
            {
                if(mp[rem]%2==1)
                return false;
            }
            else{
                int rem2=k-rem;
                if(mp[rem]!=mp[rem2])
                return false;
            }
        }
        return true;
    }
};
Given an array A[] and positive integer K, the task is to count total number of pairs in the array whose sum is divisible by K.

Example 1:

Input : 
A[] = {2, 2, 1, 7, 5, 3}, K = 4
Output : 5
Explanation : 
There are five pairs possible whose sum
is divisible by '4' i.e., (2, 2), 
(1, 7), (7, 5), (1, 3) and (5, 3)
https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
class Solution
{
    public:
    int countKdivPairs(int A[], int n, int K)
    {
        //code here
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<n;i++){
            int rem=A[i]%K;
            int rem2=(K-rem)%K;
            if(mp.find(rem2)!=mp.end())
            {
                count+=mp[rem2];
            }
            mp[rem]++;
        }
        return count;
    }
};



Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return true If you can find a way to do that or false otherwise.

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k ,0);
        for(int i=0 ; i<arr.size() ; i++){
            freq[(arr[i]%k + k)%k]++;
        }
        bool flag = false;
        if(freq[0]%2==0){
            flag = true;
        }
        for(int i=1 ; i<k ; i++){
            if(freq[i]!=freq[k-i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};