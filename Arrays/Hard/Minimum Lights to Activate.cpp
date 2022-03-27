

https://www.interviewbit.com/problems/minimum-lights-to-activate/
There is a corridor in a Jail which is N units long. Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.

All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].

Initially all lights are off.

Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.



Problem Constraints
1 <= N <= 1000

1 <= B <= 1000



Input Format
First argument is an integer array A where A[i] is either 0 or 1.

Second argument is an integer B.



Output Format
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.

int Solution::solve(vector<int> &A, int B) {
int count=0;
int i=0;
int n=A.size();
while(i<n){
    int right=min(i+B-1,n-1);
    int left=max(i-B+1,0);
    bool bulbfound=false;
    while(right>=left)
    {
        if(A[right]==1)
        {bulbfound=true;
        break;}right--;
    }
    if(bulbfound==false)
    return -1;
    count++;
i=right+B;
}
return count;
}

