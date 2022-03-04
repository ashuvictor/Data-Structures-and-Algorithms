Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
https://leetcode.com/problems/k-closest-points-to-origin/
// priority_queue <int, vector<int>, greater<int> > pq;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dist,{points[i][0],points[i][1]}});
            if(pq.size()>k)
                pq.pop();
                
        }
        while(pq.size()>0)
        {
            auto temp=pq.top().second;
            ans.push_back({temp.first,temp.second});
            pq.pop();
        }
        return ans;
    }
};