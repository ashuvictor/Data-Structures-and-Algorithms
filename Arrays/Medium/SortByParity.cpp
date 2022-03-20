
https://leetcode.com/problems/sort-array-by-parity/
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted
vector<int> sortArrayByParity(vector<int> &v)
{
	int n = v.size();
	int left = 0, right = n - 1;
	while (left < right)
	{
		while (left < n and v[left] % 2 == 0) left++;
		while (right >= 0 and v[right] % 2 != 0) right--;
		if (left >= right)
			return v;
		swap(v[left], v[right]);
		left++;
		right--;
	}
	return v;
}