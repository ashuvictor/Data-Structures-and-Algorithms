https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
int findPlatform(int arr[], int dep[], int n)
    {int ans=1;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=1,j=0;
    	while(i<n){
    	    if(arr[i]<=dep[j])
    	    {
    	        i++;ans++;
    	    }
    	    else{
    	        j++,i++;
    	    }
    	}
    	return ans;
    }
};