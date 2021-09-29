//approach 1
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        
        if(head==NULL)
        return NULL;
        
        if(head->next==NULL)
        return head;
        
        Node* curr=compute(head->next);
        
        if(head->data<curr->data){
           *(head)=*(head->next);
            return curr;
        }
        
        else{
            return head;
        }
        
        
    }
    
};

//approach 2
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        
        if(head==NULL)
        return NULL;
        
        if(head->next==NULL)
        return head;
        
        Node* curr=compute(head->next);
        
        if(head->data<curr->data){
           free(head);
            return curr;
        }
        
        else{
            head->next=curr;
            return head;
        }
        
        
    }
    
};
