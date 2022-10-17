class Solution {
public:
    int countSubsetSum(vector<int> &arr, int sum){
        int n=arr.size();
        int t[n+1][sum+1];
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0) t[i][j]=0;
                if(j==0) t[i][j]=1;
            }
        }
        
        
        for(int i=1;i<n+1;i++){
            for(int j=0; j<sum+1; j++){
                if(arr[i-1]<=j) t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                else t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
     int sum = accumulate(nums.begin(), nums.end(), 0);
        if(((sum - target) % 2 == 1) || (target > sum))
            return 0;
        
        int x = (sum - target)/2;
        
        return countSubsetSum(nums, x);
    }
};