/*
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
*/
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int beg=l,end=r;
         int merg[r-l+1];
         int i=0,center=m;m++;
         while(i<=center and m<=r){
             if(arr[l]<=arr[m])
             merg[i++]=arr[l++];
             else
             merg[i++]=arr[m++];
         }
         while(l<=center)
         merg[i++]=arr[l++];
         while(m<=r)
         merg[i++]=arr[m++];
         i=0;
         for(int j=beg;j<end;j++)
         arr[j++]=merg[i++];
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)
        return;
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,m,r);
    }
};