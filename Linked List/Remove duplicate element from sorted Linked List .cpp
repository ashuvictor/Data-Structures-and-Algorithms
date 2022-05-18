Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

Example 1:

Input:
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time.

https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

Node * uniqueSortedList(Node * head) {
    // Write your code here.
	if(head==NULL)
		return NULL;
	Node* first;
	Node* second;
	first=head;
	second=first->next;
	while(second!=NULL){
		if(first->data!=second->data){
			first=second;
			second=second->next;
		}
		else{
			first->next=second->next;
			delete(second);
			second=first->next;
		}
	}
	return head;
}