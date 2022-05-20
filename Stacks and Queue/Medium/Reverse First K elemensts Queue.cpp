
https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/#

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.
Example 1:

Input:
5 3
1 2 3 4 5

Output: 
3 2 1 4 5

Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int>st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    int temp=q.size()-k;
    while(temp--){
        int x=q.front();q.pop();
        q.push(x);
    }
    return q;
}