https://practice.geeksforgeeks.org/problems/find-optimum-operation4504/1/?category
class Solution
{
  public:
    int minOperation(int n)
    {
        int operations=0;
        while(n>0){
            if(n%2==0)
            {
                n=n/2;operations++;
            }
            else{
                n--;operations++;
            }
        }
        return operations;
    }
};

