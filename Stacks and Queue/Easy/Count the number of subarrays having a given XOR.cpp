int subarrayXor(int arr[], int n, int m)
{
      //declaring the hashtable
      //and initializing it with a count of 1
      //for 0
    unordered_map <int, int> HashTable;
    HashTable[0] = 1;
    int count = 0, curSum = 0;
    for (int i = 0; i < n; i++)
    {
        curSum ^= arr[i];
        if (HashTable[curSum ^ m] > 0)
            count += HashTable[curSum ^ m];
        HashTable[curSum]++;
    }
    return(count);
}