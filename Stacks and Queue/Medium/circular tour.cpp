

Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Example 1:

Input:
N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}. The first point from
where truck can make a circular tour is
2nd petrol pump. Output in this case is 1
(index of 2nd petrol pump).



struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
o(n^2)
O(n^2) 

 

 for(int i=0;i<n;i++)
      {
          int cnt=0;
          int start=i;
          int remaining=0;
          for(int j=i;j<n;j++)
          {
              if((p[j].petrol-p[j].distance+remaining)<0)
               break;
               remaining=(p[j].petrol-p[j].distance+remaining);
               cnt++;
               if(j==n-1&&cnt<n)
               {
                   j=-1;
               }
               if(cnt==n)
               return start;
          }
      }
      
      return -1;





      int sum=0, point=0;
       int i;
       for( i=0; i<n; i++) {
           sum+=p[i].petrol-p[i].distance;
           if(sum<0) {
               point=i+1;
               sum=0;
           }

       }
       
       int j=0;
       while(point<=n && j<point && j<n) {
           sum+=p[j].petrol-p[j].distance;
           j++;
          
       }
       if(sum<0) return -1;
       return point;
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int deficit = 0;
       int balance = 0;
       int start = 0;
       
       for(int i=0; i<n; i++) {
           balance += p[i].petrol - p[i].distance;
           if(balance < 0) {
               start = i+1;
               deficit += balance;
               balance = 0;
           }
       }
       
       if(balance + deficit >=0) 
            return start;
        return -1;
       
    }
};
