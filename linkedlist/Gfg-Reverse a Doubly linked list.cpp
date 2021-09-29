//Approach 1
struct Node* reverseDLL(struct Node * head)
{
    
    if(head==NULL)
    return NULL;
    
    if(head->next==NULL)
    return head;
    
    struct Node* curr=head;
    
    while(curr->next!=NULL){
        curr=curr->next;
    }
    
    struct Node* new_head=curr;
    
    while(curr!=NULL){
        
        curr->next=curr->prev;
        curr=curr->prev;
        
    }
    
    return new_head;
    
    
}
//Approach 2
struct Node* reverseDLL(struct Node * head)
{
    
    if(head==NULL)
    return NULL;
    
    if(head->next==NULL)
    return head;
    
    struct Node* curr=head;
    struct Node*prev_node=NULL;
    
    while(curr){
        
        curr->prev=curr->next;
        curr->next=prev_node;
        prev_node=curr;
        curr=curr->prev;
    
    }
    
    
    return prev_node;
}
