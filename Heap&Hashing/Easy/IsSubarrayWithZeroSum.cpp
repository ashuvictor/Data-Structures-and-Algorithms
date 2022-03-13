/*Subarray with zero sum
https://techiedelight.com/practice/?problem=ZeroSum
*/
class Solution
{
public:
	bool hasZeroSumSubarray(vector<int> const &nums)
	{
		unordered_set<int>s;int sum=0;
		
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			if(sum==0)
			return true;
			if(s.find(sum)!=s.end())
			return true;
			s.insert(sum);
		}
		return false;
	}
};