
https://leetcode.com/problems/implement-queue-using-stacks/
https://www.lintcode.com/problem/40/

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.


class MyQueue {
public:
    stack<int>s,s1;
    MyQueue() {
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(s.size()>1){
            auto it=s.top();
            s1.push(it);
            s.pop();
        }
        auto top=s.top();
        s.pop();
        while(!s1.empty())
        {
            auto it=s1.top();
            s1.pop();
            s.push(it);
        }
            return top;
    }
    
    int peek() {
        while(s.size()>1){
            auto it=s.top();
            s.pop();
            s1.push(it);
        }
        auto top=s.top();
        s1.push(top);
        s.pop();
        while(!s1.empty())
        {
            auto it=s1.top();
            s.push(it);
            s1.pop();
        }
            return top;
    }
    
    bool empty() {
     return s.empty();  
    }
};