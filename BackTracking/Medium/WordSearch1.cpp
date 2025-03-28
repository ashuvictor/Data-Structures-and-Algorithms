Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.
 

Example 1:

Input: board = {{a,g,b,c},{q,e,e,l},{g,b,k,s}},
word = "geeks"
Output: 1
Explanation: The board is-
a g b c
q e e l
g b k s
The letters which are used to make the
"geeks" are colored.
https://practice.geeksforgeeks.org/problems/word-search/1/?page=1&difficulty[]=1&status[]=solved&category[]=Graph&sortBy=submissions
class Solution {
public:
   bool solve(vector<vector<char>>& board, string word,int i,int j){
       if(word.size()==0)
       return true;
       if(i<0 or i>=board.size() or j<0 or j>board[0].size() or board[i][j]!=word[0])
       return false;
       char c=board[i][j];
       board[i][j]='*';//mark as visited
       string subs=word.substr(1);
       bool isFound=solve(board,subs,i-1,j) or solve(board,subs,i,j+1) or solve(board,subs,i+1,j)or solve(board,subs,i,j-1);
       board[i][j]=c;
       return isFound;
   }
    bool isWordExist(vector<vector<char>>& board, string word) {
       for(int i=0;i<board.size();i++){
           for(int j=0;j<board[0].size();j++){
               if(solve(board,word,i,j))
               return true;
           }
       }
       return false;
    }
};


class Solution {
public:
    bool solve(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        // Base case: if we have found the entire word
        if (index == word.size()) return true;

        // Check boundaries and character match
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[index]) {
            return false;
        }

        // Mark the current cell as visited
        char temp = mat[i][j];
        mat[i][j] = '*';

        // Explore all four possible directions
        bool isFound = solve(mat, word, i + 1, j, index + 1) ||
                       solve(mat, word, i - 1, j, index + 1) ||
                       solve(mat, word, i, j + 1, index + 1) ||
                       solve(mat, word, i, j - 1, index + 1);

        // Restore the character (backtracking)
        mat[i][j] = temp;

        return isFound;
    }

    bool isWordExist(vector<vector<char>>& mat, string word) {
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (solve(mat, word, i, j, 0))  // Start DFS search from (i, j)
                    return true;
            }
        }
        return false;
    }
};
