class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
        ListNode *head=new ListNode();
        ListNode *res=head;
        
        while(l1 && l2)
        {
            if(l1->val<=l2->val)
            {
                res->next=l1;
                l1=l1->next;
            }
            else
            {
                 res->next=l2;
                l2=l2->next; 
            }
            res=res->next;
        }
        if(l1)
        {
              res->next=l1;
                l1=l1->next;    
        }
        if(l2)
        {
                 res->next=l2;
                l2=l2->next; 
            
        }
        
        return head->next;
    }
};
