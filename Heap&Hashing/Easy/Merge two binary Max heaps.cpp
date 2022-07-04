Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

 

Example 1:

Input  : 
n = 4 m = 3
a[] = {10, 5, 6, 2}, 
b[] = {12, 7, 9}
Output : 
{12, 10, 9, 2, 5, 7, 6}



// Tc - O(logn)

//Inserting every ele of array b into array a meanwhile heapifying

 

 void heapify(vector<int> &a){
         int i=a.size()-1;
            while( true ){
                  int par = (i-1)/2;
                  if( a[i] > a[par] ){
                     swap(a[i],a[par]);
                     i=par;
                  }
                  else 
                  return;
            }
     }
   vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
         for(int i=0; i<b.size(); i++){
               
                  int val = b[i];
                  a.push_back(val);
                  heapify(a);
         }
         return a;
   }