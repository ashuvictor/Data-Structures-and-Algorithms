ith index means that the counter is i and ith index will contain the last element of the increasing subsequence
put everywhere INT_MAX and traverse from the end and first element where it is not INT_MAX
https://leetcode.com/problems/longest-increasing-subsequence/
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
    int longestSubsequence(int n, int a[])
    {
        vector <int> lis;
    lis.push_back(a[0]);
    int len=1;
    
    for(int i=1;i<n;i++){
        if(a[i]>lis[len-1]){
            lis.push_back(a[i]);
            len++;
        }
        else{
            int idx=bs(lis,a[i],0,len-1);
            lis[idx]=a[i];
            
        }
    }
    return len;
    }
};
time-o(nlogn)
second
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
      int dp[n];
    
    for(int i=0;i<n;i++)
    dp[i]=1;
      for(int i=1;i<n;i++){
          for(int j=0;j<i;j++){
              if(a[j]<a[i])
              dp[i]=max(dp[i],dp[j]+1);
          }
      }
      int ma=INT_MIN;
      for(int i=0;i<n;i++)
      ma=max(dp[i],ma);
      return ma;
    }
};
