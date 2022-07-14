


int maxSum(int arr[], int i, vector<int> &dp)
{
    // base case
    if (i < 0)
        return 0;
 
    // this condition check is necessary to avoid segmentation fault at line 21
    if (i == 0)
        return arr[i];
 
    // returning maxSum for already processed indexes of array
    if (dp[i] != -1)
        return dp[i];
 
    // including current element and the next consecutive element in subsequence
    int a = arr[i] + arr[i - 1] + maxSum(arr, i - 3, dp);
 
    // not including the current element in subsequence
    int b = maxSum(arr, i - 1, dp);
 
    // including current element but skipping next consecutive element
    int c = arr[i] + maxSum(arr, i - 2, dp);
 
    // returning the max of above 3 cases
    return dp[i] = max(a, max(b, c));
}



int maxSumWO3Consec(int arr[], int n)
{
    // Stores result for subarray arr[0..i], i.e.,
    // maximum possible sum in subarray arr[0..i]
    // such that no three elements are consecutive.
    int sum[n];
   
    // Base cases (process first three elements)
    if (n >= 1)
        sum[0] = arr[0];
   
    if (n >= 2)
        sum[1] = arr[0] + arr[1];
   
    if (n > 2)
        sum[2] = max(sum[1], max(arr[1] +
                               arr[2], arr[0] + arr[2]));
   
    // Process rest of the elements
    // We have three cases
    // 1) Exclude arr[i], i.e., sum[i] = sum[i-1]
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i]
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1]
    for (int i = 3; i < n; i++)
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]),
                     arr[i] + arr[i - 1] + sum[i - 3]);
   
    return sum[n - 1];
}