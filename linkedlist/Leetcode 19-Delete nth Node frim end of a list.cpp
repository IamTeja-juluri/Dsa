//using recursion
class Solution {
public:
    
    ListNode* helper(ListNode* node,int &n){
        
        if(node==NULL)
            return NULL;
        
        node->next=helper(node->next,n);
        n-=1;
        if(n==0)
            return node->next;
        
        return node;
    } 
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return NULL;
        return helper(head,n);
    }
};

//approach 1
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)
            return NULL;
        
        ListNode*curr=head;
        
        int count=0;
        
        while(curr!=NULL)
        {
            count+=1;
            curr=curr->next;
        }
        
        if(count==n)
            return head->next;
    
         curr=head;
        count=count-n;
        
        ListNode* prev=NULL;
        
        for(int i=0;i<count;i++){
            prev=curr;
            curr=curr->next;
        }
        
        prev->next=curr->next;
        
        return head;
    }
};

//approach 2 imp(optimal)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head==NULL)
            return NULL;
        
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode *fast=dummy;
        ListNode* slow=dummy;
        
        for(int i=1;i<=n+1;i++){
            fast=fast->next;
        }
        
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        
        return dummy->next;
    }
};









