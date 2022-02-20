/*
SORT BINARY ARRAY
https://techiedelight.com/practice/?problem=SortBinaryArray
Given a binary array, in-place sort it in linear time and constant space. The output should contain all zeroes, followed by all ones.

Input : [1, 0, 1, 0, 1, 0, 0, 1]
Output: [0, 0, 0, 0, 1, 1, 1, 1]

Input : [1, 1]
Output: [1, 1]

*/

class Solution
{
public:
	void sortArray(vector<int> &nums)
	{
		// Write your code here...
		int k=0;
		int n=nums.size();
		for(int i=0;i<n;i++){
			if(nums[i]==0){
				nums[k++]=0;
			}
		}
		for(int i=k;i<n;i++)
		nums[i]=1;
	}
};
