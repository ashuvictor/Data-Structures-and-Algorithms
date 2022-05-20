
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
    vector<long long>ans;
    queue<long long>q;
    for(auto i=0;i<K-1;i++)
   { if(A[i]<0)
    q.push(A[i]);}
    
    for(auto i=K-1;i<N;i++){
        if(A[i]<0)
        q.push(A[i]);
        if(!q.empty()){
            ans.push_back(q.front());
            if(q.front()==A[i-K+1])
            q.pop();
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
 }


 APPROACH 2
 vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
         deque<long long int> dq;
         vector<long long> ans;
         int negative = -1;
         
         //process first window
         for(int i=0; i<K; i++) {
             if(A[i] < 0) {
                 dq.push_back(i);
             }
         }
         
         //push ans for FIRST window
         if(dq.size() > 0) {
             ans.push_back(A[dq.front()]);
         }
         else
         {
             ans.push_back(0);
         }
         
         //now process for remaining windows
         for(int i = K; i<N; i++) {
             //first pop out of window element
             
             
             if(!dq.empty() && (i - dq.front())>=K ) {
                 dq.pop_front();
             }
             
             //then push current element
             if(A[i] < 0)
                dq.push_back(i);
             
            // put in ans
            if(dq.size() > 0) {
                 ans.push_back(A[dq.front()]);
            }
            else
            {
                ans.push_back(0);
            }
         }
         return ans;
 }
