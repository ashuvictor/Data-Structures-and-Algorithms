https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
 bool comp(Item i1,Item i2){
        double unit1=(i1.value*1.0)/i1.weight;
        double unit2=(i2.value*1.0)/i2.weight;
        return (unit1>unit2);
    }
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
   
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       double ans=0;
       sort(arr,arr+n,comp);
       for(int i=0;i<n;i++){
           if(arr[i].weight>=W)
           {
               double unit=(arr[i].value)*1.0/arr[i].weight;
               ans+=W*unit;break;
           }
           ans+=arr[i].value;
           W-=arr[i].weight;

}
return ans;
       
    }
        
};