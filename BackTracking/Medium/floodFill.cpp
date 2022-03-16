floodFill
https://leetcode.com/problems/flood-fill/

class Solution {
public:
   void dfs(vector<vector<int>>&image,int sr,int sc,int newColor,int oldC){
       if(sr<0 or sr>=image.size() or sc<0 or sc>=image[0].size() or image[sr][sc]!=oldC or image[sr][sc]==newColor)
           return;
       image[sr][sc]=newColor;
       dfs(image,sr+1,sc,newColor,oldC);//down
          dfs(image,sr-1,sc,newColor,oldC);//up
          dfs(image,sr,sc-1,newColor,oldC);//left
          dfs(image,sr,sc+1,newColor,oldC);//right
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
     dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};
