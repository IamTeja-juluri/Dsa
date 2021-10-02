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
        
        ListNode* curr=head,*prev=NULL;
        
        while(curr){
            
           ListNode* nextNode=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nextNode;
            
        }
        
        return prev;
        
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!l1 && !l2)
            return NULL;
        
        if(l1 && !l2)
            return l1;
        
        if(!l1 && l2)
            return l2;
        
        l1=reverse(l1);
        l2=reverse(l2);
        
        int sum=0,carry=0;
        ListNode* newNode=NULL;
        ListNode* dummyHead=NULL;
        ListNode* res=NULL;
            
        while(l1 || l2){
            
            sum=carry+(l1?l1->val:0)+(l2?l2->val:0);
    
            newNode=new ListNode(sum%10);
            carry=sum>9?1:0;
            
            
            if(dummyHead==NULL){
                dummyHead=newNode;
                res=newNode;
            }
            
            else{
                res->next=newNode;
                res=res->next;
            }
            
            
            
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
    
        }
        
        if(carry){
            res->next=new ListNode(carry);
            res=res->next;
        }
            
      return   res=reverse(dummyHead);
        
        
    }
};
