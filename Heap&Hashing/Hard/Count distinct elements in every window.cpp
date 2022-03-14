
https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/#
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.


class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<k-1;i++)
        {
            mp[A[i]]++;
        }
        for(int i=k-1,j=0;i<n;i++,j++){
            mp[A[i]]++;    //acquire
            ans.push_back(mp.size());  //work
            int freq=mp[A[j]]; //removal
            if(freq==1)
            mp.erase(A[j]);
            else
            mp[A[j]]--;
        }
        return ans;
    }
};