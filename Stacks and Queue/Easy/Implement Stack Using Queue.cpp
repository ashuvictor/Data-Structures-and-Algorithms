

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
class MyStack {
public:
    queue<int>q1,q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty())
            q1.push(x);
        else
        {
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }
    
    int pop() {
        int top=q1.front();
        q1.pop();
        return top;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
class MyStack {
    queue<int> q;
public:
    
    void push(int x) {
        q.push(x);
        for(int i = 0 ; i<q.size()-1 ; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x ; 
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
