Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.

Input Format:

The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:

Return a 2-d matrix that satisfies the given conditions.
Constraints:

1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:
https://www.interviewbit.com/problems/set-matrix-zeros/
Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]


Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]



void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int col1=1;
    int rows=A.size();
    int cols=A[0].size();
    for(int i=0;i<rows;i++){
        if(A[i][0]==0)
        col1=0;
        for(int j=1;j<cols;j++){
            if(A[i][j]==0)
            A[i][0]=A[j][0]=0;
        }
    }
    for(int i=rows-1;i>=0;i--){
        for(int j=cols-1;j>=1;j--){
            if(A[i][0]==0 or A[j][0]==0)
            A[i][j]=0;
            if(col1==0)
            A[i][0]=0;
        }
    }
}