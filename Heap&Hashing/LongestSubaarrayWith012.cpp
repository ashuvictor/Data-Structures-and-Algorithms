/*Longest Subarray with equal 0 1 and 2's
https://www.youtube.com/watch?v=MRoWBJvJeLQ
here we wll br checking for the difference that is  1 -0 and  2-1

*/
int solution(int arr[],int n){
    unordered_map<string,int>mp;
    int countz=0,counto=0,countt=0;
    int ans=0;
int delta10=counto-countz;
int delta21=countt-counto;
string key=delta10+"#"+delta21;
mp[key]=-1;
for(int i=0;i<n;i++){
    if(arr[i]==0)
    { countz++;

    }
    else if(arr[i]==1){
counto++;
    }
    else
    {
  countt++;
    }
     delta10=counto-countz;
 delta21=countt-counto;
 key=delta10+"#"+delta21;
 if(mp.find(key)!=mp.end()){
     int idx=mp[key];
     int len=i-idx;
     ans=max(ans,len);
 }
 else{
     mp[key]=i;
 }
}


return ans;
}