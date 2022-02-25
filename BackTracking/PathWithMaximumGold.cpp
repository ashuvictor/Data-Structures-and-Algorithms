class Solution {
public:
    int fun(vector<vector<int>>&grid,int i,int j){
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]==0)
            return 0;
        int current=grid[i][j];
        grid[i][j]=0;
        int ans=current;
        int ans1=0;
        ans1=max(ans1,fun(grid,i+1,j));//down
        ans1=max(ans1,fun(grid,i,j-1));//left
        ans1=max(ans1,fun(grid,i,j+1));//right
        ans1=max(ans1,fun(grid,i-1,j));//up
        ans+=ans1;
        grid[i][j]=current;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]>0)
                    ans=max(ans,fun(grid,i,j));
            }
        }
        return ans;
    }
};