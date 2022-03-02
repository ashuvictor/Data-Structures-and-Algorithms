/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/
class Solution {
public:
    bool isValid(vector<int>&weights,int days,int mid){
        int sum=0;
        int req_days=1;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                req_days++;sum=weights[i];
                
            }
            if(req_days>days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int mx=-1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mx)
                mx=weights[i];
            sum+=weights[i];
        }
        if(days==weights.size())
            return mx;
        int start=mx,end=sum;
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(isValid(weights,days,mid)){
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};