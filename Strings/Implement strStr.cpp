class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0;
    int n=needle.size();
        while(j<haystack.size()){
            if(j-i+1<n)
            {
                j++;
            }
            else if(j-i+1==n){
                string temp=haystack.substr(i,j-i+1);
                if(temp==needle)
                    return i;
                else
                {
                    i++;j++;
                }
                
            }
        }
        return -1;
    }
};