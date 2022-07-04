get middle element of stack in o(1)
use array -o(n/2)
linked list
maintain the middle element

use doubly ll
cnt odd push no op
even then move to prev
pop cnt odd
move to next and if even nothing



/* C++ Program to implement a stack
that supports findMiddle() and
deleteMiddle in O(1) time */
#include <bits/stdc++.h>
using namespace std;

class myStack {
	struct Node {
		int num;
		Node* next;
		Node* prev;

		Node(int num) { this->num = num; }
	};

	// Members of stack
	Node* head = NULL;
	Node* mid = NULL;
	int size = 0;

public:
	void push(int data)
	{
		Node* temp = new Node(data);
		if (size == 0) {
			head = temp;
			mid = temp;
			size++;
			return;
		}

		head->next = temp;
		temp->prev = head;

		// update the pointers
		head = head->next;
		if (size % 2 == 1) {
			mid = mid->next;
		}
		size++;
	}

	int pop()
	{
	int data=-1;
		if (size != 0) {
		data=head->num;
			if (size == 1) {
				head = NULL;
				mid = NULL;
			}
			else {
				head = head->prev;
				head->next = NULL;
				if (size % 2 == 0) {
					mid = mid->prev;
				}
			}
			size--;
		}
	return data;
	}

	int findMiddle()
	{
		if (size == 0) {
			return -1;
		}
		return mid->num;
	}

	void deleteMiddle()
	{
		if (size != 0) {
			if (size == 1) {
				head = NULL;
				mid = NULL;
			}
			else if (size == 2) {
				head = head->prev;
				mid = mid->prev;
				head->next = NULL;
			}
			else {
				mid->next->prev = mid->prev;
				mid->prev->next = mid->next;
				if (size % 2 == 0) {
					mid = mid->prev;
				}
				else {
					mid = mid->next;
				}
			}
			size--;
		}
	}
};

int main()
{
	myStack st;
	st.push(11);
	st.push(22);
	st.push(33);
	st.push(44);
	st.push(55);
	st.push(66);
	st.push(77);
	st.push(88);
	st.push(99);
	cout <<"Popped : "<< st.pop() << endl;
	cout <<"Popped : "<< st.pop() << endl;
	cout <<"Middle Element : "<< st.findMiddle() << endl;
	st.deleteMiddle();
	cout <<"New Middle Element : "<< st.findMiddle() << endl;
	return 0;
}
// This code is contributed by Nikhil Goswami
// Updated by Amsavarthan LV
Method 2: Using a standard stack and a deque 

We will use a standard stack to store half of the elements and the other half of the 
elements which were added recently will be present in the deque. Insert operation on myStack will add an element into 
the back of the deque. The number of elements in the deque stays 1 more or equal to that in the stack, however, whenever the number 
of elements present in the deque exceeds the number of elements in the stack by more than 1 we pop an element from the front of the deque 
and push it into the stack. The pop operation on myStack will remove an element from the back of the deque. If after the pop operation, the 
size of the deque is less than the size of the stack, we pop an element from the top of the stack and insert it back into the front of the deque 
so that size of the deque is not less than the stack. We will see that the middle element is always the front element of the deque. So deleting of 
the middle 
element can be done in O(1) if we just pop the element from the front of the deque. 


#include <bits/stdc++.h>
using namespace std;

class myStack {
	stack<int> st;
	deque<int> dq;

public:
	void add(int data)
	{
		dq.push_back(data);
		if (dq.size() > st.size() + 1) {
			int temp = dq.front();
			dq.pop_front();
			st.push(temp);
		}
	}

	void pop()
	{
		int data = dq.back();
		dq.pop_back();
		if (st.size() > dq.size()) {
			int temp = st.top();
			st.pop();
			dq.push_front(temp);
		}
	}

	int getMiddleElement() {
	return dq.front();
	}

	void deleteMiddleElement()
	{
		dq.pop_front();
		if (st.size() > dq.size()) { // new middle element
			int temp = st.top();	 // should come at front of deque
			st.pop();
			dq.push_front(temp);
		}
	}
};

int main()
{
	myStack st;
	st.add(2);
	st.add(5);
	cout << "Middle Element: " << st.getMiddleElement() << endl;
	st.add(3);
	st.add(7);
	st.add(4);
	cout << "Middle Element: " << st.getMiddleElement() << endl;
	st.deleteMiddleElement();
	cout << "Middle Element: " << st.getMiddleElement() << endl;
	st.deleteMiddleElement();
	cout << "Middle Element: " << st.getMiddleElement() << endl;
	st.pop();
	st.pop();
	st.deleteMiddleElement();
}

//By- Vijay Chadokar
