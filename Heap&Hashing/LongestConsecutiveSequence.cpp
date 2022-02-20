/* LONGEST CONSECUTIVE SEQUENCE 
https://leetcode.com/problems/longest-consecutive-sequence/
*/
METHOD 1
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int count=1;
        int ans=0;
        int i;
        for(i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i])
                count++;
            else if(nums[i-1]==nums[i])
                continue;
            else{
              ans=max(ans,count);  
              count=1;}
        }
        if(i==nums.size()){
            ans=max(ans,count);
        }
        return ans; 
    }
};

METHOD 2
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hashset;
	   for(auto x:nums){
		   hashset.insert(x);
	   } 
    int ans=0;
	for(auto num:nums){
		if(!hashset.count(num-1)){  
int current=num;
            int currentlength=1;
		
		while(hashset.count(current+1)){
			current+=1;
			currentlength+=1;
		}
		ans=max(ans,currentlength);
	}
	
	}
     return  ans;
    }
};