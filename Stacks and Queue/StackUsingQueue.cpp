Implement a Stack using two queues q1 and q2.
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
       q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
       int ans=-1;
       if(q1.empty())
       return ans;
       while(q1.size()>1){
           q2.push(q1.front());
           q1.pop();
       }
       ans=q1.front();
       q1.pop();
       swap(q1,q2);
       return ans;
}