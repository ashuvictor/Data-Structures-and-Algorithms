/*Find maximum length subarray having a given sum
https://techiedelight.com/practice/?problem=MaximumLengthSubarray

*/
method1 
void findMaxLenSubarray(int nums[], int n, int S)
{
    // `len` stores the maximum length of subarray with sum `S`
    int len = 0;
 
    // stores ending index of the maximum length subarray having sum `S`
    int ending_index = -1;
 
    // consider all subarrays starting from `i`
    for (int i = 0; i < n; i++)
    {
        int target = 0;
 
        // consider all subarrays ending at `j`
        for (int j = i; j < n; j++)
        {
            // sum of elements in the current subarray
            target += nums[j];
 
            // if we have found a subarray with sum `S`
            if (target == S)
            {
                // update length and ending index of max length subarray
                if (len < j - i + 1)
                {
                    len = j - i + 1;
                    ending_index = j;
                }
            }
        }
    }
 
    // print the subarray
    printf("[%d, %d]", ending_index - len + 1, ending_index);
}
METHOD 2
class Solution
{
public:
	vector<int> findMaxLenSubarray(vector<int> const &nums, int target)
	{
		// Write your code here...
		vector<int>ans;
		int ending=-1;
		unordered_map<int,int>map;
		map[0]=-1;
		int sum=0;int len=0;
		for(int i=0;i<nums.size();i++){
			sum+=nums[i];
			if(map.find(sum)==map.end())
			map[sum]=i;
             // if the sum is seen for the first time, insert the sum with its
        // into the map
			if(map.find(sum-target)!=map.end() and len<i-map[sum-target])
			{
				len=i-map[sum-target];
				ending=i;
			}
		}
		if(ending!=-1)
		{
			for(int i=ending-len+1;i<=ending;i++)
			ans.push_back(nums[i]);
		}
		return ans;
	}
};