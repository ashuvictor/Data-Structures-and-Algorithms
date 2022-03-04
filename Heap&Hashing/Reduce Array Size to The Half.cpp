
You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
https://leetcode.com/problems/reduce-array-size-to-the-half/
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
    // reverse the ordering and then 
        //key->val and it should be desc order
        //key can be unique
        multimap<int,int,greater<int>>mm;
        for(auto it:mp){
            mm.insert({it.second,it.first});
        }
        int n=arr.size();
        int sum=n;int count=0;
        for(auto it=mm.begin();it!=mm.end();it++){
            sum-=it->first;
           count++;
            if(sum<=n/2)
                return count;
        }
        return count;
            
    }
};