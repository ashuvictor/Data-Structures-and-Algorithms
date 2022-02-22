/*Minimum number of deletions to make a sorted sequence
Given an array arr of size N, the task is to remove or delete the minimum number of elements
 from the array so that when the remaining elements are placed in the same sequence order form an increasing sorted sequence.
Input: N = 5, arr[] = {5, 6, 1, 7, 4}
Output: 2
Explanation: Removing 1 and 4
leaves the remaining sequence order as
5 6 7 which is a sorted sequence.
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence3248/1/?page=3&difficulty[]=0&category[]=Dynamic%20Programming&sortBy=submissions
*/
class Solution{
public:
int bs(vector <int> lis,int ele,int l,int h){
    while(l<h){
        int m=(l+h)>>1;
        
        if(lis[m]<ele){
            l=m+1;
        }
        else{
            h=m;
        }
    }
    return l;
}
 int minDeletions(int arr[], int n) 
{ 
     
    vector <int> lis;
    lis.push_back(arr[0]);
    int len=1;
    
    for(int i=1;i<n;i++){
        if(arr[i]>lis[len-1]){
            lis.push_back(arr[i]);
            len++;
        }
        else{
            int idx=bs(lis,arr[i],0,len-1);
            lis[idx]=arr[i];
            
        }
    }
    return n-len;
} 
};
