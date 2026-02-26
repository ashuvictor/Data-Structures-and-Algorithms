floodFill
https://leetcode.com/problems/flood-fill/

class Solution {

    private void dfs(int[][] image, int sr, int sc, int newColor, int oldC) {
        // boundary + stop conditions
        if (sr < 0 || sr >= image.length ||
            sc < 0 || sc >= image[0].length ||
            image[sr][sc] != oldC ||
            image[sr][sc] == newColor) {
            return;
        }

        image[sr][sc] = newColor;

        dfs(image, sr + 1, sc, newColor, oldC); // down
        dfs(image, sr - 1, sc, newColor, oldC); // up
        dfs(image, sr, sc - 1, newColor, oldC); // left
        dfs(image, sr, sc + 1, newColor, oldC); // right
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
}
