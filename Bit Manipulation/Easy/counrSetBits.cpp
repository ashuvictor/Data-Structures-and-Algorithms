class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n>0){
            int rsb=n&(-n);
            n-=rsb;
            ans++;
        }
        return ans;
    }
};