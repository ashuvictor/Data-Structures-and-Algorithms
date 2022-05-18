https://leetcode.com/problems/reverse-nodes-in-k-group/

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
time- o(n)
space-o(n)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
   //to not reverse the last group which is less than k
         ListNode* temp=head;
         for(int i=0;i<k;i++)
         {
            if(!temp)return head;
            temp=temp->next;
        }
        //reversing the first part
        ListNode* currptr;
        ListNode* prevptr;
        ListNode* nextptr;
        prevptr=NULL;nextptr=NULL;
        currptr=head;int count=0;
        while(currptr!=NULL and count<k){
            nextptr=currptr->next;
            currptr->next=prevptr;
            
            prevptr=currptr;
            currptr=nextptr;
            count++;
        }
        //aage ka recursion ke bharose
        if(nextptr)
            head->next=reverseKGroup(nextptr,k);
        return prevptr;
    }
};