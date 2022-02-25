https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1/?category
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { bool done[n]={false};
    int day=0,profit=0;
    sort(arr,arr+n,comp);
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dead-1);j>=0;j--){
            if(done[j]==false){
                day++;
                profit+=arr[i].profit;
                done[j]=true;
                break;
            }
        }
    }
    return {day,profit};
        // your code here
    } 
};