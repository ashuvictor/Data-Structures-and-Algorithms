https://leetcode.com/problems/reverse-linked-list/
Given the head of a singly linked list, reverse the list, and return the reversed list.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
  ListNode *currptr;
	ListNode *nextptr;
	ListNode *prevptr;
	prevptr=NULL;
	currptr=head;
	nextptr=NULL;
	while(currptr!=NULL){
		nextptr=currptr->next;
		currptr->next=prevptr;
		prevptr=currptr;
		currptr=nextptr;
	}
	return prevptr; 
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
 if(head==NULL or head->next==NULL)
 return head;
 ListNode* newHead=reverseList(head->next);
 head->next->next=head;
 head->next=NULL;
 return newHead;
		
    }
};
