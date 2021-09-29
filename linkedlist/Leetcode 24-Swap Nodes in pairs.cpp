class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return head;
        
       ListNode* dummy_head=head->next;
        
       ListNode* first=head;
       ListNode* second=head->next; 
       ListNode* prev;
        
       while(true){
           
           prev=first;
           first->next=second->next;
           second->next=first;
           first=first->next;
         
           if(first==NULL)
               break;
         
           second=first->next;
           if(second==NULL)
               break;
         
           prev->next=second;

       } 
        
      return dummy_head;
        
       
    }
};
