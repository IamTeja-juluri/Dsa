class Solution {
public:
    int getDecimalValue(ListNode* head) {
      
        if(head==NULL)
            return 0;
        
        ListNode*curr=head;
        ListNode*prev=NULL;
        
        while(curr!=NULL){
            
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        
        int ans=0,i=0;
        
        while(prev!=NULL){
            
            ans=ans+(prev->val)*(pow(2,i++));
            prev=prev->next;
            
        }
        
        return ans;
        
    }
};
