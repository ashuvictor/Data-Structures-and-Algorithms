/*
You are given two numbers represented as integer arrays A and B, where each digit is an element.

You have to return an array which representing the sum of the two given numbers.

The last element denotes the least significant bit, and the first element denotes the most significant bit.



Problem Constraints
1 <= |A|, |B| <= 105
0 <= Ai, Bi <= 9


Input Format
The first argument is an integer array A. The second argument is an integer array B.


Output Format
Return an array denoting the sum of the two numbers.


Example Input
Input 1:
A = [1, 2, 3]
B = [2, 5, 5]
Input 2:

A = [9, 9, 1]
B = [1, 2, 1]


Example Output
Output 1:
[3, 7, 8]
Output 2:

[1, 1, 1, 2]
https://www.interviewbit.com/problems/array-sum/
*/

vector<int> sum(vector<int> &A, vector<int> &B, int n, int m){
    vector<int> ans; 
    int i = n - 1, j = m - 1;
    int carry = 0, s = 0;
    while (j >= 0) {
        s = A[i] + B[j] + carry;
        ans.push_back(s % 10);
        carry = s / 10;
        i--;
        j--;
    }
    while (i >= 0) {
        s = A[i] + carry;
        ans.push_back(s % 10);
        carry = s / 10;
        i--;
    }
    if (carry>0){
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int m = B.size();
    if (n >= m)
        return sum(A, B, n, m);
    else
        return sum(B, A, m, n);
}