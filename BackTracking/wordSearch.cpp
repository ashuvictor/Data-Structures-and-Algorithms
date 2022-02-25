class Solution {
public:
   bool fun(vector<vector<char>>&board,string word,int i,int j,int idx){
       if(idx==word.size())
           return true;
       if(i<0 or i>=board.size() or j<0 or j>=board[0].size()or board[i][j]!=word[idx])
           return false;
       board[i][j]='$';
       bool a,b,c,d;
      a =fun(board,word,i,j+1,idx+1);
       b=fun(board,word,i,j-1,idx+1);
       c=fun(board,word,i-1,j,idx+1);
       d=fun(board,word,i+1,j,idx+1);
       board[i][j]=word[idx];
       if(a or b or c or d)
           return true;
       return false;
   }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                bool x=false;
                if(board[i][j]==word[0])
                {   x=fun(board,word,i,j,0);
                    if(x)
                        return true;
                }
            }
        }
        return false;
    }
};