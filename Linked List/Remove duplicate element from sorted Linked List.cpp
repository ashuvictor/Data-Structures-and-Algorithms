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

// root: head node
Node *removeDuplicates(Node *root)
{   Node *p;Node *q;
p=root;
q=p->next;
while(q!=NULL){
    if(p->data!=q->data){
        p=q;
        q=q->next;
    }else{p->next=q->next;
    delete(q);
        q=p->next;
    }}
    return root;

 // your code goes here
}