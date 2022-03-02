class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        vector<int>count(26,0);
        string ans;
        for(int i=0;i<arr.size();i++)
        count[arr[i]-'a']++;
        for(int i=1;i<26;i++)  //this will store the number of elements which are smaller
        count[i]+=count[i-1];                   //then we will go to that position and print it
        
        string s(arr.length(),' ');
        for(int i=0;i<arr.length();i++)
        {
            int x=--count[arr[i]-'a'];    //we will go to that position where it is 
            s[x]=arr[i];
        }
        return s;
    }
};
