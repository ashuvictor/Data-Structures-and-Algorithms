
https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

Example 1:

Input:
N = 4
value[] = {5,2,2,4}
Output: 5 2 4
Explanation:Given linked list elements are
5->2->2->4, in which 2 is repeated only.
So, we will delete the extra repeated
elements 2 from the linked list and the
resultant linked list will contain 5->2->4


Node * removeDuplicates( Node *head) 
{   unordered_set<int>s;
    Node *p;Node *q;

p=q=head;
s.insert(head->data);
head=head->next;
while(head!=NULL){
    if(s.find(head->data)==s.end()){
        q->next=head;
        q=head;
        s.insert(q->data);
    }head=head->next;
}
q->next=NULL;return p;

 // your code goes here
}