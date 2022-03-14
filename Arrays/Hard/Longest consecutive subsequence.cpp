Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.

https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
 int findLongestConseqSubseq(int arr[], int N)
    {
      set<int>hashset;
      for(int i=0;i<N;i++)
      hashset.insert(arr[i]);
      int ans=1;
      for(int i=0;i<N;i++){
          if(!hashset.count(arr[i]-1)){
              int current_length=1;
              int current=arr[i];
              while(hashset.count(current+1)){
                  current+=1;
                  current_length+=1;
              }
          ans=max(ans,current_length);}
      }
      return ans;
    }
};