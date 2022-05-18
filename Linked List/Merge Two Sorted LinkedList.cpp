You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result;
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        if(l1->val<l2->val){
            result=l1;
            result->next= mergeTwoLists(l1->next,l2);
        }
        else{
            result=l2;
            result->next= mergeTwoLists(l1,l2->next);
        }
        return result;
    }
};