Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.
https://www.interviewbit.com/problems/meeting-rooms/

int Solution::solve(vector<vector<int> > &A) {
    sort(A.begin(),A.end());
    //min heap is end first
    priority_queue<int,vector<int>,greater<int>>pq;//end time of the meeting 
    for(int i=0;i<A.size();i++){
        if(pq.empty())
        {
            pq.push(A[i][1]);
        }
        else{
        if(pq.top()<=A[i][0])
        {
            pq.pop();
            pq.push(A[i][1]);
        }
        else{
             pq.push(A[i][1]);
        }
        }
    }
    return pq.size();
}
