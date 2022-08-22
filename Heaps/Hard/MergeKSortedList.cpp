
https://leetcode.com/problems/merge-k-sorted-lists/
https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
class compare{
  public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> minHeap;
        ListNode* head=NULL;
        ListNode* tail=NULL;
        int totalLists = lists.size();
        if(totalLists==0){
            return head;
        }
        for(int i=0;i<totalLists;i++){
            if(lists[i]){
               minHeap.push(lists[i]);  
            }
        }
        while(!minHeap.empty()){
            ListNode* top = minHeap.top();
            minHeap.pop();
            if(head==NULL && tail==NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail=top;
            }
            if(top->next){
                minHeap.push(top->next);
            }
        }
        return head;
    }
};


class Solution{
  public:
    //Function to merge K sorted linked list.
    struct compare{
        bool operator()(struct Node* a,struct Node* b){
           return a->data>b->data;
        }
    };
    Node * mergeKLists(Node *arr[], int K)
    {
       priority_queue<Node*,vector<Node*>,compare>q;
       for(int i=0;i<K;i++)
       q.push(arr[i]);
       Node* dummy=new Node(0);
       Node* last=dummy;
        while(!q.empty())
        {
            Node* current=q.top();
            q.pop();
            last->next=current;
            last=current;
            if(current->next)
            q.push(current->next);
            
        }
        return dummy->next;
    }
};