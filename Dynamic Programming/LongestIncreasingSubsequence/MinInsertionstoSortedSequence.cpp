/* min insertions to sorted sequence
https://practice.geeksforgeeks.org/problems/minimum-insertions-to-sort-an-array0535/1/?page=1&difficulty[]=1&status[]=solved&category[]=Dynamic%20Programming&sortBy=submissions#
Given an array arr of size N, the task is to sort this array in
 a minimum number of steps where in one step you can remove any array element from its position and insert it in any other position.
*/
class Solution{
		

	public:
	int minInsertions(int arr[], int N) 
	{ 
vector<int>dp(N,1);
for(int i=1;i<N;i++){
    for(int j=0;j<i;j++){
        if(arr[j]<=arr[i]){
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
}
return N-*max_element(dp.begin(),dp.end());
	} 
};