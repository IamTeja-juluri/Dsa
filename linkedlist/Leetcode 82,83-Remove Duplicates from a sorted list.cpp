class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return head;
        
        ListNode* curr=head;
        ListNode*  dummy_node=new ListNode(0,head);
        ListNode* prev=dummy_node;
       
        while(curr!=NULL ){
            
           if(curr->next!=NULL && curr->val==curr->next->val){
               
               while(curr->next!=NULL && curr->val==curr->next->val){
                   
                   curr=curr->next;
               }
               prev->next=curr->next;
           }
            else{
                prev=prev->next;
            }
            curr=curr->next;
        }
        
        return dummy_node->next;
        
    }
};
