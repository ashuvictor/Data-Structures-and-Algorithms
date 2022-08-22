
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
https://practice.geeksforgeeks.org/problems/minimum-swaps/1/

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
    v.push_back({nums[i],i});
}
sort(v.begin(),v.end());
int count=0;
for(int i=0;i<n;i++){
    if(v[i].second==i){
        continue;
    }
    else{
        swap(v[i],v[v[i].second]);
        count++;i--;
    }
}
return count;
}
};

