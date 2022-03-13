/*

Given an array containing only 0’s, 1’s, and 2’s, sort it in linear time and using constant space.

Input : [0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2]
https://techiedelight.com/practice/?problem=DutchNationalFlagProblem
*/

class Solution
{
public:
	void sortArray(vector<int> &nums)
	{
		// Write your code here...
		int low=0,mid=0;
		int high=nums.size()-1;
		while(mid<=high){
			switch(nums[mid]){
				case 0:swap(nums[low++],nums[mid++]);break;
				case 1:mid++;break;
				case 2:swap(nums[mid],nums[high--]);break;
			}
		}
	}
};
