class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL || k==0)
            return head;
        
        ListNode* curr=head;
        int n=0;
        ListNode* last=NULL;
        
        while(curr){
            n+=1;
            last=curr;
            curr=curr->next;
        }
        
        
        if(k>n){
            k=k%n;
        }
        
         if(k==n || k==0)
            return head;
        
        
        curr=head;
        
        for(int i=1;i<n-k;i++){
            curr=curr->next;
        }
        
        ListNode* new_head=curr->next;
        curr->next=NULL;
        
        last->next=head;
        
        return new_head;
        
        
    }
};
