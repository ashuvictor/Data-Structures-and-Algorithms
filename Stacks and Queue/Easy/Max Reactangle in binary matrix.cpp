class Solution{
    private:
   vector<int>next_element(int* heights,int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int cur=heights[i];
            while(s.top()!=-1 and heights[s.top()]>=cur){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
       vector<int>pre_element(int* heights,int n){
        vector<int>ans(n);
        stack<int>s;
        s.push(-1);
        for(int i=0;i<n;i++){
            int cur=heights[i];
            while(s.top()!=-1 and heights[s.top()]>=cur){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
      int largestRectangleArea(int* heights , int n) {
        
       
        vector<int>pre(n);
        pre=pre_element(heights,n);
        vector<int>next(n);
        next=next_element(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-pre[i]-1;
            int newarea=l*b;
            area=max(area,newarea);
        }
        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area = largestRectangleArea(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]!=0){
                    M[i][j]=M[i][j]+M[i-1][j];
                }
                else{
                    M[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(M[i],m));
        }
        return area;
    }
};