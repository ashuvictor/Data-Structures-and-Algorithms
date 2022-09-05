Node* reverseDLL(Node * head)
{Node *p;Node *temp;
p=head;
while(p!=NULL){
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    p=p->prev;
    if(p!=NULL and p->next==NULL )
    head=p;
}
return head;
    //Your code here
}
