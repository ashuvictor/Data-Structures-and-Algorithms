/*Given an integer rowIndex,
 return the rowIndexth (0-indexed) row of the Pascal's triangle.
 https://leetcode.com/problems/pascals-triangle-ii/
 */
 class Solution {
public:
    vector<int> getRow(int rowIndex) {
         if(rowIndex==0)
            return {1};
        else if(rowIndex==1)
            return {1,1};

       vector <int> prev = {1,1};
       for(int i  = 2;i<=rowIndex;i++){
           vector<int>temp(i+1);//we initialize a vector with size at the current level
           temp[0] = 1;
           temp[i] = 1;//since the first and last index is always going to be one
           for(int j = 1;j<i;j++){//we use the previous level to compute the value of index 1 to the second last index
              temp[j] = prev[j-1]+prev[j];
           }
           prev = temp;//setting the current level to the previous level before the next iteration
       }
       return prev;
        
    }
};