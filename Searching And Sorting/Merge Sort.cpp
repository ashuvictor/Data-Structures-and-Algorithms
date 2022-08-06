class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int start=l,center=m,end=r;
         int merg[r-l+1];int i=0;m++;
         while(l<=center and m<=r)
         {
             if(arr[l]<=arr[m])
             {
                 merg[i++]=arr[l++];
                 
             }
             else
             {
                 merg[i++]=arr[m++];
             }
         }
         while(l<=center)
         merg[i++]=arr[l++];
         while(m<=r)
         merg[i++]=arr[m++];
         i=0;
         for(int j=start;j<=end;j++)
         arr[j]=merg[i++];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)
        return;
        int m=(l+r)>>1;
     mergeSort(arr,l,m);
     mergeSort(arr,m+1,r);
     merge(arr,l,m,r);
    }
};