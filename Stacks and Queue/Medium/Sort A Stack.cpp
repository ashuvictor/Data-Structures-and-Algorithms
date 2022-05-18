https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0?source=youtube&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio

You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.
We can only use the following functions on this stack S.
is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}