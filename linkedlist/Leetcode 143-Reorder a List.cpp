/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* reverse(ListNode* head){
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(curr){
          
          ListNode* temp=curr->next;
          curr->next=prev;
          prev=curr;
          curr=temp;  
            
        }
        return prev;
        
    }
    
    
    void reorderList(ListNode* head) {
        
        if(head==NULL)
            return;
        
        if(head->next==NULL)
            return;
        
        ListNode* slow=head,*fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* dummy=slow;
        
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        dummy->next=NULL;
        
        ListNode* curr=head;
    
        while(slow!=NULL){
            
            ListNode* next_node=curr->next;
            curr->next=slow;
            curr=slow;
            slow=slow->next;
            curr->next=next_node;
            curr=curr->next;
            
        } 
       
         return;
        
    }
};
