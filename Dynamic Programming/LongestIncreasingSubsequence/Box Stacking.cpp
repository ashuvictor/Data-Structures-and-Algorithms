You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.
 

Note: 
Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.

 

Example 1:

Input:
n = 4
height[] = {4,1,4,10}
width[] = {6,2,5,12}
length[] = {7,3,6,32}
Output: 60
Explanation: One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner)
(12, 32, 10) (10, 12, 32) (6, 7, 4) 
(5, 6, 4) (4, 5, 6) (2, 3, 1) (1, 2, 3)
Hence, the total height of this stack is
10 + 32 + 4 + 4 + 6 + 1 + 3 = 60.
No other combination of boxes produces a
height greater than this.

https://practice.geeksforgeeks.org/problems/box-stacking/1#
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    struct volume{
        int l,b,h;
    };
    static bool comp(volume &v1,volume &v2){
        return (v1.l*v1.b>v2.l*v2.b);
    }
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        volume v[6*n];
        for(int i=0;i<n;i++){
            v[i]={height[i],width[i],length[i]};
             v[i+n]={height[i],length[i],width[i]};
              v[i+2*n]={width[i],height[i],length[i]};
               v[i+3*n]={width[i],length[i],height[i]};
                v[i+4*n]={length[i],height[i],width[i]};
                 v[i+5*n]={length[i],width[i],height[i]};
        }
        sort(v,v+6*n,comp);
        int dp[6*n];
        int ans=0;
        for(int i=0;i<6*n;i++){
            int maxa=0;
            for(int j=i-1;j>=0;j--){
                if(v[j].l>v[i].l and v[j].b>v[i].b)
                {
                    maxa=max(maxa,dp[j]);
                }
            }
            dp[i]=maxa+v[i].h;
            ans=max(ans,dp[i]);
            
        }
        return ans;
    }
};