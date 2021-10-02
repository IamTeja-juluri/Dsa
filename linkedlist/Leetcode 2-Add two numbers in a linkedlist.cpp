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
    ListNode* push(int data){
        
        ListNode* newNode=new ListNode(data);
        
        return newNode;
    }
    
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL && l2==NULL)
            return NULL;
        
        if(l1 && !l2)
            return l1;
        
        if(!l1 && l2)
            return l2; 
        
        int carry=0,sum=0;
        
        ListNode *res=NULL,*head=NULL;
        
        while(l1 || l2){
                 
        sum=carry+(l1?l1->val:0)+(l2?l2->val:0);
            
            
            if(sum>9)
                carry=1;
            else 
                carry=0;
            
            ListNode* temp=push(sum%10);
            
            if(res==NULL){
                res=temp;
                head=temp;
            }
            else{
                res->next=temp;
                res=temp;
                
            }
             if(l1){
                l1=l1->next;
            }
            
            if(l2){
                l2=l2->next;
            }
                
            
        }
        
        if(carry){
            
            ListNode* temp=push(carry);
            res->next=temp;
            res=temp;
            
        }
        
        
        return head;
        
    }
};
