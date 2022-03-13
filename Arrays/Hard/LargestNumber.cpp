/*  Given a list of non-negative integers nums, 
arrange them such that they form the largest number and return it.

Since the result may be very
 large, so you need to return a string instead of an integer.
 leetcode-https://leetcode.com/problems/largest-number/
 InterViewBit-
 */
class Solution {
public:
    static bool comp(int a,int b){  //always the comparator will be static
        string x=to_string(a);
        string y=to_string(b);
        return x+y>y+x;
    }
    string largestNumber(vector<int>& nums) {
     string res="";
        sort(nums.begin(),nums.end(),comp);
        for(int i=0;i<nums.size();i++)
            res+=to_string(nums[i]);
        return res[0]=='0'?"0":res;
    }
};

InterViewBit-https://www.interviewbit.com/problems/largest-number/
static bool comp(string x,string y){
   
    return x+y>y+x;
}
string Solution::largestNumber(const vector<int> &A) {
    string res="";
    // sort(A.begin(),A.end(),comp);
    vector<string>nums;
    for(int i=0;i<A.size();i++)
    nums.push_back(to_string(A[i]));
     sort(nums.begin(),nums.end(),comp);
for(int i=0;i<nums.size();i++)
res+=nums[i];
int i=0;
    while(res[i]=='0'){
        i++;
    }
    if(i==res.length())
     res="0";
  
return res;
}