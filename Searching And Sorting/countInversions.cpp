class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[], long long int &count, long long int start, long long int mid, long long int end){
        long long temp[end-start+1];
        long long int i=start;
        long long int j=mid+1;
        long long int k=0;
        while(i<=mid && j<=end){
            if(arr[i]>arr[j]){
                temp[k++]=arr[j++];
                count+= mid-i+1;
            }
            else{
                temp[k++]=arr[i++];
            }
        }
        
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=end){
            temp[k++]=arr[j++];
        }
        
        for(long long int i=start; i<=end; i++){
            arr[i]=temp[i-start];
        }
    }
    void mergeSort(long long arr[], long long int &count, long long int start, long long int end){
        if(start<end){
            long long int mid=(start+end)/2;
            mergeSort(arr,count,start,mid);
            mergeSort(arr,count,mid+1,end);
            merge(arr,count,start,mid,end);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Her
        long long int count=0;
        mergeSort(arr,count,0,N-1);
        return count;
    
    }

};