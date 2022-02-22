/*Given an array of digits (values lie in range from 0 to 9). 
The task is to count all the sub sequences possible in array such that in each subsequence
 every digit is greater than its previous digits in the subsequence.
 Input : 
a[] = {1, 2, 3, 4}
Output: 
15
Explanation :
There are total increasing subsequences
{1}, {2}, {3}, {4}, {1,2}, {1,3}, {1,4},
{2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4},
{1,3,4}, {2,3,4}, {1,2,3,4}
https://practice.geeksforgeeks.org/problems/count-increasing-subsequences3134/1/?page=1&difficulty[]=1&status[]=solved&category[]=Dynamic%20Programming&sortBy=submissions#
*/
class Solution{
    public:
    unsigned long long int countSub(int arr[], int n)
    {
        vector<unsigned long long int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    dp[i]+=dp[j];
                }
            }
        }
        unsigned long long int sum=0;
        for(int i=0;i<n;i++)
        sum+=dp[i];
        return sum;
    }
};