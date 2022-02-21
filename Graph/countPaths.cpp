/* Count the paths 
https://practice.geeksforgeeks.org/problems/count-the-paths4332/1/?page=1&difficulty[]=0&category[]=Graph&sortBy=submissions
*/
class Solution {
public:
		int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    int ans=0;
	    if(s==d)
	    return 1;
	    for(auto x:edges){
	        if(x[0]==s){
	            ans+=possible_paths(edges,n,x[1],d);
	        }
	    }
	    return ans;
	}
};