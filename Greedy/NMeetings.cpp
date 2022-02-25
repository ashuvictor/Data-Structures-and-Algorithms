https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1/?category

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int>i1,pair<int,int>i2){
        if(i1.second==i2.second)
        return i1.first<i2.first;
        return i1.second<i2.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>timing;
        for(int i=0;i<n;i++){
            timing.push_back({start[i],end[i]});
        }
        sort(timing.begin(),timing.end(),comp);
        int i=0,j=1;
        int ans=1;
        while(j<n){
            if(timing[i].second<timing[j].first){
                i=j;j++;ans++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }