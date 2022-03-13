Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.


Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.
https://practice.geeksforgeeks.org/problems/heap-sort/1/#
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {  // get the children and if they have more value then swap
    
    
      // Your Code Here
      int largest=i;
      int left=2*i+1;
      int right=2*i+2;
      if(left<n and arr[left]>arr[largest])
        largest=left;
        if(right<n and arr[right]>arr[largest])
        largest=right;
        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here  
    for(int i=(n-2)/2;i>=0;i--){
        //instead of starting from the leaf nodes we will start from the internal node
        heapify(arr,n,i);
    }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i=n-1;i>=0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
    
};