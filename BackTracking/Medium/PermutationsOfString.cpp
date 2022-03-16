void solve(vector<int>&A,vector<vector<int>>&ans,int i){
    if(i==A.size())
    {
        ans.push_back(A);
        return;
    }
    for(int j=i;j<A.size();j++){
        swap(A[i],A[j]);
        solve(A,ans,i+1);
        swap(A[i],A[j]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>>ans;
    solve(A,ans,0);
    return ans;
}