/*  Subarray with equal 0 and 1  
https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1/#
  treat 0 as -1 and 1 as +1 
  make map of sum if you get the sum again add its frequency*/

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    { long long int ans=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int sum=0;
    for(auto x=0;x<n;x++){
        if(arr[x]==0)
        sum+=-1;
        else
        sum+=1;
        if(mp.find(sum)!=mp.end())
        {ans+=mp[sum];
        mp[sum]++;}
        else
        mp[sum]=1;
    }
    return ans;
        //Your code here
    }
};