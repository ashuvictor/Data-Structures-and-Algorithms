Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
https://leetcode.com/problems/merge-intervals/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        if(intervals.size()==0)
            return mergedIntervals;
        sort(intervals.begin(),intervals.end());
        vector<int>tempInterval=intervals[0];
        for(auto it:intervals){
            if(it[0]<=tempInterval[1])
                tempInterval[1]=max(tempInterval[1],it[1]);
            else{
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merged;
        if(intervals.size()==0)
            return merged;
        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(merged.back()[1]>=intervals[i][0])
            {
                merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};