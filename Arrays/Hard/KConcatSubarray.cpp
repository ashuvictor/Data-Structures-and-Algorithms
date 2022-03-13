/* https://leetcode.com/problems/k-concatenation-maximum-sum/
Given an integer array arr and an integer k, modify the array by repeating it k times.

For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].

Return the maximum sub-array sum in the modified array.
 Note that the length of the sub-array can be 0 and its sum in that case is 0.
 */
class Solution {
public:
    int kadane(vector<int>&arr){
        int maxsum=arr[0];
        int currsum=arr[0];
        for(int i=1;i<arr.size();i++){
            currsum=max(currsum+arr[i],arr[i]);
            maxsum=max(maxsum,currsum);
        }
        return maxsum%1000000007;
    }
    int kadaneoftwo(vector<int>&arr){
        vector<int>arrx(arr.size()*2,0);
        for(int i=0;i<arr.size();i++){
            arrx.push_back(arr[i]);
        }        
        for(int i=0;i<arr.size();i++){
            arrx.push_back(arr[i]);
        }   
        int maxsum=kadane(arrx);
        return maxsum%1000000007;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(arr.size()==0)
            return 0;
        long long sum=accumulate(arr.begin(),arr.end(),0)%1000000007;
        if(k==1)
            return kadane(arr);
        if(sum%1000000007<0)
            return kadaneoftwo(arr);
        if(sum%1000000007>=0)
            return kadaneoftwo(arr)+(((k-2)*sum)%1000000007)%1000000007;
        return 0;
    }

};