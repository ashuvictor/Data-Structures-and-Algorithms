


agar mini se bada toh normal value
and agar chota then it is encrypted value
class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push({val,val});
        }
        else
        {
            st.push({val,min(st.top().second,val)});
        }
    }
    
    void pop() {
        if(!st.empty());
        st.pop();
    }
    
    int top() {
     return st.top().first;   
    }
    
    int getMin() {
        return st.top().second;
    }
};





#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};