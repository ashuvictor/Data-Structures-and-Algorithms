Given a dictionary that contains mapping of employee and his manager as a number of (employee, manager) pairs like below. 

{ "A", "C" },
{ "B", "C" },
{ "C", "F" },
{ "D", "E" },
{ "E", "F" },
{ "F", "F" } 

In this example C is manager of A, 
C is also manager of B, F is manager 
of C and so on.
 string ceo="";
findCount(map<string,string>employess)
{
    map<string,set<int>>tree;   // managers and employees
    for(auto x:employess)
    {
   string manager=x.first;
   if(manager==x.second)
   ceo=x.second;
   else{
       if(tree.find(manager)!=mp.end())
       {
           tree[x.first]={manager};
       }
       else{
           tree[x.first]=manager;
       }
   }

    }
}traverse and get the size
