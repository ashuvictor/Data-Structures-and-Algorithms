
Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
x(position at which tail is connected) = 2
Output: True
Explanation: In above test case N = 3.
The linked list with nodes N = 3 is
given. Then value of x=2 is given which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop.
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head==NULL)
        return false;
        map<Node*,bool>visited;
        Node* temp=head;
        while(temp!=NULL){
            if(visited[temp]==true)
            return true;
           
            visited[temp]=true; temp=temp->next;
        }
        return false;
    }
};
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
         Node* slow=head;
         Node* fast=head;;
         while(fast!=NULL and fast->next!=NULL)
         {
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast)
             return true;
             
         }
         return false;
         // your code here
    }
};//each time the distance between them decreases


https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
Given a linked list of N nodes such that it may contain a loop.

A loop here means that the last node of the link list is connected to the node at position X. If the link list does not have any loop, X=0.

Remove the loop from the linked list, if it is present.  


Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
     |____|    
A loop is present. If you remove it 
successfully, the answer will be 1. 

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
              Node* slow=head,*fast=head;bool flag=1;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                flag=0;break;
            }
        }
        if(flag)
        return;
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        while(slow->next!=fast)
        {
            slow=slow->next;
        }
        slow->next=NULL;
        
    }
};

Find first node of loop in a linked list
Difficulty Level : Medium

Write a function findFirstLoopNode() that checks whether a given Linked List contains a loop. If the loop is present then it returns point to the first node of the loop. Else it returns NULL.

Node* detectAndRemoveLoop(Node* head)
{
    // If list is empty or has only one node
    // without loop
    if (head == NULL || head->next == NULL)
        return NULL;
 
    Node *slow = head, *fast = head;
    // Move slow and fast 1 and 2 steps
    // ahead respectively.
    slow = slow->next;
    fast = fast->next->next;
    // Search for loop using slow and
    // fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    // If loop does not exist
    if (slow != fast)
        return NULL;
    // If loop exists. Start slow from
    // head and fast from meeting point.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}