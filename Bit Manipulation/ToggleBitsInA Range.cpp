#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int tc;
	cin>>tc;
	while(tc--)
	{
	    int n,l,r;
	    cin>>n>>l>>r;
	    
	    int val = 0;
	    int power = 0;
	    int mask = 1;
	    int i=1;
	    //Include all rightmost bits as it is
	    while(i<l)
	    {
	        if(mask&n)
	            val += pow(2,power);
	        mask<<=1;
	        power+=1;
	        ++i;
	    }
	   //Toggle bits in range and include
	    while(i<=r)
	    {
	        if(!(mask&n))
	            val += pow(2,power);
	        mask<<=1;
	        power+=1;
	        ++i;
	    }
	    //Include all leftmost bits as it is
	    while(i<=10)
	    {
	        if(mask&n)
	            val += pow(2,power);
	        mask<<=1;
	        power+=1;
	        ++i;
	    }
	    cout<<val<<"\n";
	}
	return 0;
}