bool isCircular(struct Node *head){
  
    struct Node* curr=head;
    
    int ans=1;
    
    while(curr->next!=head){
        
        curr=curr->next;
        if(curr==NULL)
        {
            ans=0;
            break;
        }
    }
    
    if(ans==0){
        return false;
    }
   
    return true;
}
