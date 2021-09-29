class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      
        if(head==NULL)
            return NULL;
        
        
        ListNode*curr=head;
        ListNode*prev=NULL;
        
        while(m>1){
            prev=curr;
            curr=curr->next;
            m-=1;
            n-=1;
        }
        
        ListNode*connection=prev;
        ListNode*tail=curr;
        
        while(n>0){
            
            ListNode*next_node=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next_node;
            n-=1;
            
        }
        
       if(connection!=NULL) 
       connection->next=prev;
       else
           head=prev;
        
       tail->next=curr;
       return head;   
    }
};
