  Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
Keep in mind the following conditions :

Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than K units away from him.
Example 1:

Input:
N = 5, K = 1
arr[] = {P, T, T, P, T}
Output: 2
Explanation: Maximum 2 thieves can be 
caught. First policeman catches first thief 
and second police man can catch either second 
or third thief.
https://practice.geeksforgeeks.org/problems/e47329920b4e75869ea7b0e9b7c59ea145ccc22c/1/#
  
  class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        queue<int>police; // queue to store index of police
        queue<int>chor;// queue to store index of thief
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]=='P')
            {
                police.push(i);
            }
            else
            {
                chor.push(i);
            }
        }
        int ans=0;
        while(police.empty()==false && chor.empty()==false)
        {
            if(abs(police.front()- chor.front())<=k)
            {//  if thief is within the reach of the policeman
                ans++;
                police.pop();
                chor.pop();
            }
            else if(police.front()<chor.front())
            //// thief lies beyond the reach of the current policeman
            {
                police.pop();
            }
            else
            {// thief is not reachable from any of the police
            //So pop thief
                chor.pop();
            }
        }
        return ans;
      
    }
};
  
  vector<int>police;
       vector<int>thief;
       for(int i=0;i<n;i++){
           if(arr[i]=='P')
           police.push_back(i);
           else
           thief.push_back(i);
       }
       int i=0,j=0;int ans=0;
       while(i<police.size() and j<thief.size())
       {
           if(abs(police[i]-thief[j])<=k)
           {
               ans++;j++;i++;
           }
           else if(police[i]>thief[j])
           {
               j++;
           }
           else{
               i++;
           }
       }
       return ans;