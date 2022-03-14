/*brute force will
https://leetcode.com/problems/trapping-rain-water/
for every building min(max_left_building,max_right_building)-heights[i]
keep on adding it to the ans
*/
class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();
        if(n<=2)
            return 0;
        vector<int>left(n),right(n);
        int leftmax=height[0];
        left[0]=0;
        for(int i=1;i<n;i++){
            left[i]=leftmax;
            leftmax=max(leftmax,height[i]);
        }
        int rightmax=height[n-1];
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=rightmax;
            rightmax=max(rightmax,height[i]);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            if(height[i]<left[i] and height[i]<right[i])
                ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};


class Solution {
public:
   int trap(vector<int>& height) {
        
        int n = height.size(); 
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        
        while(left<=right){
            
            if(height[left]<=height[right]){

                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                
                left++;
            }
            else{

                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                
                right--;
            }
        }
        return res;
    }
};