class Solution {
public:
    bool isSafe(vector<string>&temp,int i,int j){
        for(int x=0;x<i;x++){
            for(int y=0;y<temp.size();y++){
                if(temp[x][y]=='Q'){
                    if(y==j or(abs(x-i)==abs(y-j))){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    void fun(int i,int n,vector<vector<string>>&ans,vector<string>&temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(temp,i,j))
            {
                temp[i][j]='Q';
                fun(i+1,n,ans,temp);
                temp[i][j]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        fun(0,n,ans,temp);
        return ans;
    }
};