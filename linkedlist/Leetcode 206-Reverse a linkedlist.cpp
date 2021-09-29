//iterative approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};
//Recursive approach

class Solution {
public:
  
    ListNode* reverseList(ListNode* head) {
     
        if(head==NULL)
            return NULL;
         if(head->next==NULL)
         {
             return head;
         }
        
        ListNode* temp=reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
        
    }
};


