
https://practice.geeksforgeeks.org/problems/circular-linked-list/1/
Given head, the head of a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.

Note: The linked list does not contains any inner loop.

Example 1:

Input:
LinkedList: 1->2->3->4->5
(the first and last node is connected,
i.e. 5 --> 1)
Output: 1
bool isCircular(Node* head){
    // Write your code here.
if(head==NULL)
	return true;
	Node* temp=head->next;

	while(temp!=NULL and temp!=head){
	
		temp=temp->next;
	}
	if(temp==head)
		return true;
	else
		return false;
}
bool isCircular(Node* head){
    // Write your code here.
	Node* temp;
	temp=head;
	while(temp!=NULL){
		if(temp->next==head)
			return true;
		temp=temp->next;
	}
	return false;
}