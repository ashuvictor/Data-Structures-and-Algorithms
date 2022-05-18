
https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0

You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.
A stack is a linear data structure where both insertion and deletion of elements take place at the top. It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, on the top of the stack only.
Example :-
INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]

The above example contains an odd number of elements, hence the middle element is clearly the (N+1) / 2th element, which is removed from the stack in the output.

void solve(stack<int>&inputStack, int count, int size) {
    //base case
    if(count == size/2) {
        inputStack.pop();
        return ;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
	//RECURSIVE CALL
    solve(inputStack, count+1, size);
    
    inputStack.push(num);
    
}

void deleteMiddle(stack<int>&inputStack, int N){
	
  	int count = 0;
    solve(inputStack, count, N);
   
}