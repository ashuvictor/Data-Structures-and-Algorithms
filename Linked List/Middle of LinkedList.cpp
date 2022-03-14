
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

https://leetcode.com/problems/middle-of-the-linked-list/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow;
               ListNode* fast;
        slow=head;
        fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};