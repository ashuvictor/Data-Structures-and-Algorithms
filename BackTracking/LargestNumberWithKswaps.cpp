https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string str,int n,int k,string& ans,int index)
   {
        
        if(k==0)
            return;
       
        char maxchar = str[index];
        for(int i=index+1;i<n;i++)
        {

            if (maxchar<str[i])
                maxchar=str[i];
        }
     
        
        if(maxchar!=str[index])
            k--;
    
        for(int i=n-1;i>=index;i--)
        {
            
            if (str[i]==maxchar) 
            {
                swap(str[index], str[i]);
                if (ans<str)
                    ans=str;
               
                solve(str,n,k,ans,index+1);
                swap(str[index], str[i]);//backtracking step
        }
    }
}
    string findMaximumNum(string str, int k)
    {
       string ans = str;
       int n=str.length();
       solve(str,n,k,ans,0);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends