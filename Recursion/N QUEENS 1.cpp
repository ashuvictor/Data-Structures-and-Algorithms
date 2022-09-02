

class Solution {
public:
    bool isSafe(vector<string>&temp,int i,int j){
        for(int x=0;x<i;x++){
            for(int y=0;y<temp.size();y++){
                if(temp[x][y]=='Q')
                if(y==j or abs(x-i)==abs(y-j))
                    return false;
            }
        }
        return true;
    }
    void solve(int i,int n,vector<string>&temp,vector<vector<string>>&ans){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(temp,i,j))
            {
                temp[i][j]='Q';
                solve(i+1,n,temp,ans);
                temp[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        solve(0,n,temp,ans);
        return ans;
    }
};


class Solution {
public:
    bool isSafe(vector<vector<bool>>&board,int row,int col){
        for(int x=0;x<row;x++){
            for(int y=0;y<board.size();y++){
                if(board[x][y])
                {
                    if(y==col or abs(x-row)==abs(y-col))
                        return false;
                }
            }
        }
        return true;
    }
    int solve(vector<vector<bool>>&board,int row){
        if(row==board.size())
            return 1;
        int count=0;
        for(int i=0;i<board.size();i++){
            if(isSafe(board,row,i))
            {
                board[row][i]=true;
                count+=solve(board,row+1);
                board[row][i]=false;
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<vector<bool>>board(n,vector<bool>(n,false));
        return solve(board,0);
    }
};